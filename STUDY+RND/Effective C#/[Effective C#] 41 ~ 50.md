### 41. 값비싼 리소스를 캡처하지 마라
---
- 클로저(Closure)에 사용된 지역변수는 캡쳐된다
- 캡처된 변수를 사용하는 델리게이트가 가비지화될 때 까지 해당 변수는 가비지로 간주되지 않는다.
- 일반적으로 단순 메모리 리소스만 사용한다면 적절한 시점에 가비지로 수집될 것이기 때문에 신경쓸 필요없지만
- IDisposable을 구현한 무거운 리소스를 참조할 경우 신경써야 한다.
    ```
    var counter = 0;
    var numbers = Extensions.Generate(30, () => counter++);
    ```
- 위 코드는 다음과 같은 코드를 생성한다.
    ```
    private class Closure
    {
        public int generatedCounter;
        public int generatorFunc() => generatedCounter++;
    }
    
    var c = new Closure();
    c.generatedCounter = 0;
    var sequence = Extensions.Generate(30, new Func<int>(c.generatorFunc));
    ```
- 내부적으로 중첩클래스가 정의되며, 이 클래스는 Extensions.Generate가 사용하는 델리게이트에 바인딩된다.
- 만약 아래 코드처럼  메서드로 시퀀스를 반환하여 델리게이트를 계속 사용한다면,
- Closure 객체의 레퍼런스 c는 지역변수임에도 델리게이트에 바인딩 되었기 때문에 메서드를 벗어나서도 여전히 살아남게된다.
    ```
    public IEnumerable<int> MakeSequence()
    {
        var counter = 0;
        var numbers = Extensions.Generate(30, () => counter++);
        return numbers;
    }
    
    // 컴파일러가 생성하는 코드
    public static IEnumerable<int> MakeSequence()
    {
        var c = new Closure();
        c.generatedCounter = 0;
        var sequence = Extensions.Generate(30, new Func<int>(c.generatorFunc));
        return sequence;
    }
    ```


　

### 42. IEnumerable\<T\> 데이터 소스와 IQueryable\<T\> 데이터 소스를 구분하라
---
- IQueryable와 IEnumerable는 거의 동일한 API 정의를 갖기 때문에 상호 교환 가능하다.
- 하지만 이 두 인터페이스는 동작 방식도 매우 다르고 성능도 차이 난다.
- 결과값은 동일하지만 동작 방식은 다른 예시
    ```
    // 일반적인 LINQ to SQL 쿼리로 IQueryable\<T\>의 기능을 이용한다.
    // where 절과 order 절이 모두 결합된 단일의 T-SQL 구문을 만들어서 데이터베이스를 한 번만 호출
    var q =
        from c in dbContext.Customers
        where c.City == "London"
        select c;
    
    var finalAnswer =
        from c in q
        orderby c.Name
        select c;
    
    // 데이터베이스 객체를 IEnumerable<T> 시퀀스로 변경.
    var q =
        (from c in dbContext.Customers
        where c.City == "London"
        select c).AsEnumerable();
    
    // 정렬 작업은 로컬 머신에서 수행된다.
    var finalAnswer =
        from c in q
        orderby c.Name
        select c;
    ```
- 두 번째 예는 데이터베이스 객체를 IEnumerable\<T\> 시퀀스로 변경하기 때문에 데이터베이스가 아니라 로컬에서 더 많은 작업을 수행하게 된다.
- 쿼리문이 IEnumerable\<T\> 시퀀스를 반환하므로 그다음 작업은 LINQ to Objects 구현체와 델리게이트를 이용하여 수행된다.
- 대부분의 경우 쿼리 작업을 수행할 때 IEnumerable\<T\>보다는 IQueryable\<T\>를 사용하는 편이 훨씬 효율적이다.
- **IEnumerable\<T\>**
    > - 쿼리식 내의 람다 표현식과 함수 매개변수를 나타내기 위해 델리게이트를 사용한다.
    > - 모든 메서드가 로컬 머신에서 수행된다. 따라서 모든 데이터를 메모리로 가져와야 한다.
- **IQueryable\<T\>**
    > - 표현식 트리를 이용하여 이를 처리한다.
    > - 데이터가 실제 위치하고 있는 컴퓨터에서 수행한다.
    > - 코드로 표현할 수 있는 쿼리 표현식이 IEnumerable\<T\>에 비해 제한적이다.
- IQueryable\<T\>는 각각의 메서드를 분석하지 않는다.
- 따라서 쿼리 표현식이 다른 메서드를 호출한다면 Enumerable구현체를 사용하도록 변경해야 한다.
    ```
    private bool IsValidProduct(Product p) => p.ProductName.LastIndexOf('C') == 0;
    
    // 다음 코드는 반환된 컬렉션을 순회할 때 예외를 유발한다.
    var q1 = from p in dbContext.Products
            where IsValidProduct(p)
            select p;
    
    // 다음 코드는 정상 작동한다.
    // 성능보다 안정성을 원한다면 쿼리 결과를 IEnumerable<T>로 변환하여 예외를 회피할 수 있다.
    var q2 = from p in dbContext.Products.AsEnumerable()
            where IsValidProduct(p)
            select p;
    ```
- 특정 메서드가 동일한 T 타입에 대해서 IEnumerable<T>와 IQueryable<T>를 이용한 쿼리를 모두 지원해야 하는 경우
    ```
    // 만약 런타입 타입이 IQueryable이라면 IQueryable을 반환하고,
    // 반대로 IEnumerable타입이면 LINQ to Objects를 사용하여 IQueryable을 구현한 래퍼를 생성하여 반환한다.
    // 즉, IQueryable을 구현하고 있는 경우 그 구현체를 사용하고, IEnumerable만을 구현하고 있는 경우에도 문제없이 동작한다.
    // string.LastIndexOf() 메서드는 LINQ To SQL 라이브러리를 통해 올바르게 해석 가능한 메서드 중 하나이다.
    public static IEnumerable<Product> ValidProducts(this IEnumerable<Product> products) =>
        from p in products.AsQueryable()
        where p.ProductName.LastIndexOf('C') == 0
        select p;
    ```


　

### 43. 쿼리 결과의 의미를 명확히 강제하고, Single()과 First()를 사용하라
---
- LINQ는 단일의 값을 반환하는 메서드도 포함하고 있다.
- 정확히 1개의 요소만을 가져오려는 의도를 명확히 드러내기 위해 Take, Single, First를 의미적으로 구분지어서 사용하자.
    ```
    class Person
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int Score { get; set; }
    }
    
    class Program
    {
        static void Main()
        {
            var people = new List<Person>
            {
                new Person { FirstName = "Bill", LastName = "Gates", Score = 0 },
                new Person { FirstName = "Bill", LastName = "Wagner", Score = 10},
                new Person { FirstName = "Bill", LastName = "Johnson", Score = 20},
                new Person { FirstName = "Bill", LastName = "Walton", Score = 30},
            };
    
            // 시퀀스 내에 여러개의 요소가 포함되므로 예외를 일으킨다.
            var t1 = (from person in people where person.FirstName == "Bill" select person).Single();
    
            // 찾으려는 요소가 없기 때문에 예외를 일으킨다.
            var t2 = (from person in people where person.FirstName == "Larry" select person).Single();
    
            // 한개 이거나 없으면 디폴트 값(null) 반환.
            var t3 = (from person in people where person.FirstName == "Larry" select person).SingleOrDefault();
    
            // 가장 많은 득점을 한 사람을 찾는 예제. 없으면 디폴트 값(null) 반환
            var t4 = (from person in people where person.Score > 0 orderby person.Score descending select person).FirstOrDefault();
    
            // 가장 많은 득점을 한 사람을 찾는 예제. 없으면 예외 발생
            var t5 = (from person in people where person.Score > 0 orderby person.Score descending select person).First();
    
            // 세 번째로 득점을 많이 한 사람을 가져오는 예제.
            var t6 = (from person in people where person.Score > 0 orderby person.Score descending select person).Skip(2).First();
        }
    }
    ```


　

### 44. 바인딩된 변수는 수정하지 말라
---
- 다음 예는 클로저에서 캡쳐된 변수를 수정했을 때의 상황을 보여주기 위한 코드이다.
    ```
    class Utilities
    {
        public static IEnumerable<T> Generate<T>(int count, Func<T> generator)
        {
            for (int i = 0; i < count; i++)
                yield return generator();
        }
    }
    
    class Program
    {
        static void Main()
        {
            int index = 0;
            Func<IEnumerable<int>> sequence = () => Utilities.Generate(30, () => index++);
    
            index = 20;
            foreach (int n in sequence())
                Console.Write(n);
    
            Console.WriteLine("\nDone");
    
            index = 100;
            foreach (var n in sequence())
                Console.Write(n);
        }
    }
    
    /* 출력결과
    20 ... 50
    Done
    100 ... 130
    */
    ```
- 쿼리 표현식과 람다 표현식은 아래 형태로 컴파일러에 의해 변환된다.
    > - 정적 델리게이트
    > - 인스턴스 델리게이트
    > - 클로저
- 이 중 어떤 것을 선택하느냐는 람다 본문의 코드가 어떻게 작성됐느냐에 따라 결정된다.
- 예시A (인스턴스 변수 접근 X, 지역변수에 접근X)
    ```
    // 예시A (인스턴스 변수 접근 X, 지역변수에 접근X)
    {
        int[] numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        var answers = from number in numbers select number * number;
    }
    // 변환된 코드 - 별다른 변수 참조가 없기 때문에 델리게이트를 통해 참조할 정적 메서드를 생성한다.
    {
        static int HiddenFunc(int n) => (n * n);
        static Func<int, int> HiddenDelegate = null;
    
        int[] numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        if (HiddenDelegate == null)
            HiddenDelegate = new Func<int, int>(HiddenFunc);
    
        var answers = numbers.Select<int, int>(HiddenDelegate);
    }
    ```
- 예시B (인스턴스 변수에 접근하는 경우)
    ```
    // 예시B(인스턴스 변수에 접근O, 지역변수에 접근X)
    public class ModeFilter
    {
        private readonly int modulus;
        public ModeFilter(int mod) => modulus = mod;
        public IEnumerable<int> FindValues(IEnumerable<int> sequence) =>
            from n in sequence
            where n % modulus == 0
            select n * n;
    }
    
    // 변환된 코드 - 인스턴스 변수를 참조하기 위해 델리게이트를 통해 참조하는 인스턴스 메서드를 생성한다.
    public class ModeFilter
    {
        private readonly int modulus;
    
        // 새롭게 추가된 인스턴스 메서드
        private bool WhereClause(int n) => ((n % this.modulus) == 0);
    
        // 기존 스태틱 메서드
        private static int SelectClause(int n) => (n * n);
    
        // 기존 스태틱 델리게이트
        private static Func<int, int> SelectDelegate;
    
        public IEnumerable<int> FindValues(IEnumerable<int> sequence)
        {
            if (SelectDelegate == null)
                SelectDelegate = new Func<int, int>(SelectClause);
    
            return sequence
                .Where<int>(new Func<int, bool>(this.WhereClause))
                .Select<int, int>(SelectClause);
        }
    }
    ```
- 예시C (지역변수 or 메서드 매개변수에 접근하는 경우)
- 지역변수를 사용하는 클로저가 필요하기 때문에, 이 경우 상당한 추가 작업을 수행한다.
    ```
    // 예시C(지역변수 or 메서드 매개변수에 접근하는 경우)
    public class ModFilter
    {
        private readonly int modulus;
        public ModFilter(int mod) => this.modulus = mod;
        public IEnumerable<int> FindValues(IEnumerable<int> sequence)
        {
            int numValues = 0;
            return from n in sequence
                where n % modulus == 0
                select n * n / ++numValues;
        }
    }
    
    // 변환된 코드 - 클로저가 필요하기 때문에 private로 중첩 클래스를 선언한다.
    public class ModFilter2
    {
        private sealed class Closure
        {
            public ModFilter2 outer;
            public int numValues;
            public int SelectClause(int n) => ((n * n) / ++this.numValues);
        }
    
        private readonly int modulus;
        public ModFilter2(int mod) => this.modulus = mod;
        private bool WhereClause(int n) => ((n % this.modulus) == 0);
    
        public IEnumerable<int> FindValues(IEnumerable<int> sequence)
        {
            var c = new Closure();
            c.outer = this;
            c.numValues = 0;
    
            return sequence
                .Where<int>(new Func<int, bool>(this.WhereClause))
                .Select<int, int>(new Func<int, int>(c.SelectClause));
        }
    }
    ```
- 여러 개의 쿼리를 연이어 수행할 때 바인딩된 변수의 값을 수정하게 되면 지연 수행과 컴파일러의 클러저 구현 특성 때문에 예상치 않은 문제가 발생할 수 있다.
- 따라서 클로저에 의해 캡쳐되어 바인딩된 변수는 수정하지 않는 것이 좋다.
- 뭐래... ㅠㅠ


　

### 45. 메서드가 실패했음을 알리기 위해서 예외를 이용하라
---
- 반환 코드는 계산의 결과를 나타내는 용도로 사용되므로 오류가 발생했다는 사실 이외의 추가적인 정보를 전달하기가 어렵다.
- 예외는 클래스 타입이므로 개발자가 자신만의 예외 타입을 파생시킬 수 있으며 오류에 대한 추가적인 정보를 전달할 수 있다.
- 콜 스택을 통해서 적절한 catch문이 구성된 위치까지 전파된다.
- 적절한 catch문이 포함되어있지 않다면 응용프로그램이 종료되니 예외는 쉽게 무시하기 어렵다.
- 다만, 예외 발생은 성능을 저하시킬 수 있는 요인이다.
- 예외를 발생시키는 메서드를 작성할 때는 항상 예외를 유발하는 조건을 사전에 검사할 수 있는 메서드를 함께 작성할 것을 권장한다.
    ```
    public class DoesWorkThatMightFail
    {
        // 이런 식으로 사전검사 & 수행 메서드를 작성한다.
        public bool TryDoWork()
        {
            if (false == TestConditions())
                return false;
                
            Work(); // 여전히 실패할 가능성은 있지만 낮다.
            return true;
        }
        
        // 예외를 발생시킬 수 있는 코드
        public void DoWork => Work();
        
        private bool TestConditions()
        {
            ...
            return true;
        }
        
        private void Work()
        {
            ...
        }
    }
    ```


　

### 46. 리소스 정리를 위해 using과 try/finally를 활용하라
---
- 관리되지 않는 리소스를 사용하는 타입은 IDisposable 인터페이스의 Dispose 메서드를 이용하여 명시적으로 리소스를 해제해야 한다.
- 사용자 입장에서 Dispose()메서드가 항상 호출되도록 코드를 작성하기 위한 최선의 방법은 using문이나 try/finally 블록을 활용하는 것이다.
- TIPs: 중첩된 uinsg을 피하기 위해 아래와 같이 명시적으로 try/finally문을 구성하는 방법도 있다.
    ```
    public void ExecuteCommand(string connString, string commandString)
    {
        SqlConnection myConnection = null;
        sqlCommand mySqlCommand = null;
        
        try
        {
            myConnection = new SqlConnection(connString);
            mySqlCommand = new SqlCommand(commandString, myConnection);
            myConnection.Open();
            mySqlCommand.ExecuteNonQuery();
        }
        finally
        {
            mySqlCommand?.Dispose();
            myConnection?.Dispose();
        }
    }
    ```


　

### 47. 사용자 지정 예외 클래스를 완벽하게 작성하라
---
- 예외 객체에 포함된 기존 오류 관련 정보를 훼손하지 않으면서, 저수준의 에러 내용을 응용프로그램 관점으로 재해석한 정보를 예외 객체에 포함시키고자 할 때 예외 클래스 작성.
- 예외 클래스 만들기
    > - 개별 예외 클래스의 고유한 책임을 명확하게 규정해야한다.
    > - 모든 예외 클래스의 이름은 Exception으로 끝나야 한다.
    > - System.Exception클래스나 혹은 더 적절한 클래스를 상속해서 구현해야한다.
- 새로운 예외클래스를 작성할 때는 아래 네 개의 생성자를 작성하라.
    ```
    [Serializable]
    public class MyAssemblyException : Exception
    {
        // 기본 생성자
        public MyAssemblyException() : base()
        {
        }
    
        // 에러 메시지를 포함하는 생성자   
        public MyAssemblyException(string s) : base(s)
        {
        }
    
        // 에러 메시지와 내부 예외를 포함하는 생성자   
        public MyAssemblyException(string s, Exception e) : base(s, e)
        {
        }
    
        // 입력 스트림을 이용하는 생성자
        // .NET Core가 지원하는 모든 플랫폼에서 이 기능이 사용 가능한 것은 아니다.
        protected MyAssemblyException(SerializationInfo info, StreamingContext cxt) : base(info, cxt)
        {
        }
    }
    ```
- 저수준의 예외에 대해서 보다 세부적인 상태 정보를 포함하는 고수준의 예외로 변경이 필요할 때,
    ```
    public double DoSomeWork()
    {
        try
        {
            // 외부 라이브러리에서 예외가 발생할 수 있다.
            return ThirdPartyLibrary.ImportantRoutine();
        }
        catch (ThirdPartyException e)
        {
            var message = $"Problem with {e.ToString()} using library";
            throw new DoingSomeWorkException(message, e);
        }
    }
    ```


　

### 48. 강력한 예외 보증을 준수하는 것이 좋다
---
- 기본 보증 
    > - 특정 함수 내에서 발생한 예외가 이 함수를 빠져나오더라도 어떤 리소스도 누수되지 않으며, 모든 객체의 상태가 유효한 상태를 유지함을 의미한다.
    > - 이는 예외가 발생한 메서드 내에서 Finally 구문이 구현되어 있음을 의미하는 것이기도 하다.
    > - .NET CLR 은 기본 보증을 준수한다.
- 강력한 예외 보증
    > - 기본 보증에 더해, 예외 발생시에도 프로그램의 상태가 변경되지 않음을 추가로 보증하는 것을 말한다.
    > - 이는 예외로 인한 요청으로 인해 작업이 중단되었을 경우 응용프로그램이 작업을 실행하기 전 상태를 유지하는 것을 뜻한다.
    > - 즉, 작업이 온전히 완료되거나, 혹은 응용프로그램의 상태가 그대로 유지되거나 둘 중 하나의 경우만 가능해야 하며, 그 중간은 존재하지 않는다.
    > - LINQ 쿼리를 사용하면 기본적으로 강력한 예외 보증 요건을 준수하게 되므로, LINQ 쿼리를 이용하는 함수형 프로그래밍 스타일을 사용하는 것도 도움이 된다.
    > - 또한, 작업을 시작하기 전, 작업을 할 데이터에 대한 복사본을 미리 마련해놓고, 작업 도중에 문제가 발생할 경우 그 복사본으로 다시 롤백하는 개념의 방어적 코딩방도 있다.
    > - 이는, 작업 도중의 예외는 괜찮지만, 복사본을 통해 이전으로 롤백하는 부분의 예외는 있어서는 안된다.
- 예외 없음 보증
    > - 작업이 결코 실패하지 않으며, 따라서 예외가 발생하지 않음을 보증하는 것.
    > - Finalizer 나 Dispose() 같은 역할이 극히 제한된 메서드의 경우 예외 없음 보증이 필요하며 이로인해 방어적인 코딩이 필요하다.
    > - 또한 델리게이트의 대상이되는 메서드도 예외를 발생시키면 안된다.
- 실무 활용 예
    ```
    // GRC LoadDB 코드 발췌
    public static bool LoadDB(bool major = false, bool minor = false)
    {
        Log.Message($"SERVERINFO UPDATE START > (major:{major}, minor:{minor})");
    
        var info = new ServerInfo();
    
        try
        {
            if (null == Service)
            throw new Exception($"{nameof(Service)} is null");
    
            if (false == LoadChannel(info))
                throw new Exception($"failed to {nameof(LoadChannel)}");
    
            if (false == LoadGameConfig(info))
                throw new Exception($"failed to {nameof(LoadGameConfig)}");
    
            if (false == LoadLevel(info))
                throw new Exception($"failed to {nameof(LoadLevel)}");
    
            if (false == LoadEvent(info))
                throw new Exception($"failed to {nameof(LoadEvent)}");
    
            if (false == LoadPiggyBank(info))
                throw new Exception($"failed to {nameof(LoadPiggyBank)}");
    
            if (false == LoadGoods(info))
                throw new Exception($"failed to {nameof(LoadGoods)}");
    
            if (false == LoadQAConfig(info))
                throw new Exception($"failed to {nameof(LoadQAConfig)}");
    
            if (false == LoadPaybackEvent(info))
                throw new Exception($"failed to {nameof(LoadPaybackEvent)}");
    
            if (false == LoadRankingFesta(info))
                throw new Exception($"failed to {nameof(LoadRankingFesta)}");
    
            if (false == LoadDMoneyLimit(info))
                throw new Exception($"failed to {nameof(LoadDMoneyLimit)}");
    
            if (false == LoadRandomBox(info))
                throw new Exception($"failed to {nameof(LoadRandomBox)}");
        }
        catch (Exception exception)
        {
            Log.Message("SERVERINFO UPDATE FAIL");
            Log.Error($"an exception has occured > {exception}");
            return false;
        }
        finally
        {
        }
    
        Log.Message("----------------------");
        Log.Message("SERVERINFO UPDATE DONE");
        Log.Message("----------------------");
    
        if (major)
        {
            
            Log.Message($"MAJOR VER -> {MajorUpdateCount++}");
            Log.Message($"-----------> {MajorUpdateCount}");
        }
        else if (minor)
        {
            Log.Message($"MINOR VER -> {MinorUpdateCount++}");
            Log.Message($"-----------> {MinorUpdateCount}");
        }
        else
        {
            Log.Message("initialize ver");
        }
    
        Info = info;
    
        return true;
    }
    ```


　

### 49. catch 후 예외를 다시 발생시키는 것보다 예외 필터가 낫다
---
- 예외가 발생한 이후 어떠한 조건을 넣으려고 할 때, catch 안의 if 구문보다 아예 catch에서 when 키워드를 통해 조건을 거는 것이 좋다.
    ```
    var retryCount = 0;
    var dataString = default(String);
    
    while (dataString == null)
    {
        try
        {
            dataString = MakeWebRequest();
        }
        catch (TimeoutException e) when (retryCount++ < 3)
        {
            Console.WriteLine("Operation timed out. Trying again");
            Thread.Sleep(1000 * retryCount);
        }
    }
    ```
- 런타임은 예외를 처리할 수 있는 catch 문을 찾은 후 즉각 스택 되감기(stack unwinding)를 수행한다.
- 따라서 catch 구문 안으로 들어오면 try 구문에서 있었던 스택 프레임 정보들이 사라진다. 즉, 분석을 위한 주요 정보들이 모두 날라간다.
    ```
    var retryCount = 0;
    var dataString = default(String);
    
    while (dataString == null)
    {
        try
        {
            dataString = MakeWebRequest();
        }
        catch (TimeoutException e)
        {
            // 스택 되감기(stack unwinding) 수행.
            // 예외를 일으킨 메서드 내에서 선언된 지역변수의 대부분은 도달 불가능 객체가 된다.
    
            if (retryCount++ < 3)
            {
                Console.WriteLine("Operation timed out. Trying again");        
                Thread.Sleep(1000 * retryCount);
            }
            else
            {
                // 진짜 예외가 발생한 위치는 날라가고 단순히 이 위치가 호출 스택에 나타난다.
                throw;
            }
        }
    }
    ```


　

### 50. 예외 필터의 다른 활용 예를 살펴보라
---
- 활용 예 #1 - 로깅
    ```
    public static bool ConsoleLogException(Exception e)
    {
        var oldColor = Console.ForegroundColor;
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine("Error: {0}", e);
        Console.ForegroundColor = oldColor;
        return false;
    }
    
    try
    {
        data = MakeWebRequest();
    }
    // False를 반환하므로 어떤 경우에도 예외 처리문 안으로 진입하지 않는다.
    // 모든 예외에 대해서 로그를 출력한다.
    // 수행 성능에 영향을 미치지 않는다.
    catch (Exception e) when (ConsoleLogException(e))
    {
    }
    catch (TimeoutException e) when (failures++ < 10)
    {
        Console.WriteLine("Timeout error: trying again");
    }
    ```
- 활용 예 #2 - 디버깅 시 예외처리 제외 시키기
    ```
    try
    {
        data = MakeWebRequest();
    }
    catch (Exception e) when (ConsoleLogException(e))
    {
    }
    // 이와 같은 방식을 사용하면, 디버거가 붙어 있는 상태에서는 어떤 예외 처리기도 수행되지 않는다.
    // 즉, 디버깅 시에는 예외 처리기가 수행되지 않기 때문에 예외가 발생했다는 사실을 디버거가 즉각적으로 감지할 수 있게 된다.
    catch (TimeoutException e) when (failures++ < 10 && System.Diagnostics.Debugger.IsAttached == false)
    {
        Console.WriteLine("Timeout error: trying again");
        ...
    }
    catch ...
    ```
