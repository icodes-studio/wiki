### 31. 시퀀스에 사용할 수 있는 조합 가능한 API를 작성하라
---
- 반복문을 사용하여 컬렉션을 다루는 경우, 단일 작업이 아니라 여러 순회 단계를 거치는 경우가 많으며, 이런 저런 큰 비용이 발생하게 된다.
- 이럴 때 이터레이터 메서드를 만들어 사용하면 범용성과 재사용성 및 성능 좋은 패턴을 만들어 낼 수 있다.
- 이터레이터 메서드란 단일 시퀀스(IEnumerable\<T\>) 입력을 취하고, 다른 단일 시퀀스(IEnumerable\<T\>)를 반환하는 메서드를 말한다.
- 이터레이터 메서드는 필요할 때 수행되는 방식이므로 불필요한 순회를 제거하여 성능을 높일 수 있다.
- 여러 이터레이터 메서드를 조합하면 지연수행모델(deferred execution model) 덕분에 런타임 효율이 개선된다.
- 먼저 일반 메서드 방식과 이터레이터 메서드 방식의 차이를 이해해야한다.
    ```
    class Program
    {
        static void Main()
        {
            var myList = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
            Console.WriteLine("---normal method---------------");
            foreach (var item in Unique1(myList))
            {
                Console.WriteLine($"consuming: {item}");
                if (item > 2)
                    break;
            }
    
            Console.WriteLine("---iterator method-------------");
            foreach (var item in Unique2(myList))
            {
                Console.WriteLine($"consuming: {item}");
                if (item > 2)
                    break;
            }
        }
    
        static HashSet<int> Unique1(IEnumerable<int> nums)
        {
            var uniqueVals = new HashSet<int>();
            foreach (var num in nums)
            {
                Console.WriteLine($"evaluating: {num}");
                if (false == uniqueVals.Contains(num))
                    uniqueVals.Add(num);
            }
            return uniqueVals;
        }
    
        static IEnumerable<int> Unique2(IEnumerable<int> nums)
        {
            var uniqueVals = new HashSet<int>();
            foreach (var num in nums)
            {
                Console.WriteLine($"evaluating: {num}");
                if (false == uniqueVals.Contains(num))
                {
                    uniqueVals.Add(num);
                    yield return num;
                }
            }
        }
    }
    
    /* 출력결과
    ---normal method---------------
    evaluating: 1
    evaluating: 2
    evaluating: 3
    evaluating: 4
    evaluating: 5
    evaluating: 6
    evaluating: 7
    evaluating: 8
    evaluating: 9
    consuming: 1
    consuming: 2
    consuming: 3
    ---iterator method-------------
    evaluating: 1
    consuming: 1
    evaluating: 2
    consuming: 2
    evaluating: 3
    consuming: 3
    */
    ```
- Unique 메서드 동작 확인
    ```
    class Program
    {
        static void Main()
        {
            var myList = new List<int>() { 0, 3, 4, 5, 7, 3, 2, 7, 8, 0, 3, 1 };
    
            foreach (var item in Unique(myList))
                Console.WriteLine($"consuming: {item}");
        }
    
        static IEnumerable<int> Unique(IEnumerable<int> nums)
        {
            var uniqueVals = new HashSet<int>();
            foreach (var num in nums)
            {
                Console.WriteLine($"\tevaluating: {num}");
                if (false == uniqueVals.Contains(num))
                {
                    Console.WriteLine($"\tadding: {num}");
                    uniqueVals.Add(num);
                    yield return num;
                    Console.WriteLine("\treentering after yield return");
                }
            }
        }
    }
    
    /* 출력결과
            evaluating: 0
            adding: 0
    consuming: 0
            reentering after yield return
            evaluating: 3
            adding: 3
    consuming: 3
            reentering after yield return
            evaluating: 4
            adding: 4
    consuming: 4
            reentering after yield return
            evaluating: 5
            adding: 5
    consuming: 5
            reentering after yield return
            evaluating: 7
            adding: 7
    consuming: 7
            reentering after yield return
            evaluating: 3
            evaluating: 2
            adding: 2
    consuming: 2
            reentering after yield return
            evaluating: 7
            evaluating: 8
            adding: 8
    consuming: 8
            reentering after yield return
            evaluating: 0
            evaluating: 3
            evaluating: 1
            adding: 1
    consuming: 1
            reentering after yield return
    */
    ```
- 이터레이터 메서드 조합 (전체 시퀀스에 대한 순회는 단 한 번만 이뤄진다.)
    ```
    class Program
    {
        static void Main()
        {
            var myList = new List<int>() { 0, 3, 4, 5, 7, 3, 2, 7, 8, 0, 3, 1 };
            foreach (var item in Square(Unique(myList)))
                Console.WriteLine($"consuming: {item}");
        }
    
        static IEnumerable<int> Square(IEnumerable<int> nums)
        {
            foreach (var num in nums)
            {
                Console.WriteLine($"\tsquare evaluating: {num}");
                yield return num * num;
            }
        }
    
        static IEnumerable<int> Unique(IEnumerable<int> nums)
        {
            var uniqueVals = new HashSet<int>();
            foreach (var num in nums)
            {
                Console.WriteLine($"\tunique evaluating: {num}");
                if (false == uniqueVals.Contains(num))
                {
                    uniqueVals.Add(num);
                    yield return num;
                }
            }
        }
    }
    
    /* 출력결과
            unique evaluating: 0
            square evaluating: 0
    consuming: 0
            unique evaluating: 3
            square evaluating: 3
    consuming: 9
            unique evaluating: 4
            square evaluating: 4
    consuming: 16
            unique evaluating: 5
            square evaluating: 5
    consuming: 25
            unique evaluating: 7
            square evaluating: 7
    consuming: 49
            unique evaluating: 3
            unique evaluating: 2
            square evaluating: 2
    consuming: 4
            unique evaluating: 7
            unique evaluating: 8
            square evaluating: 8
    consuming: 64
            unique evaluating: 0
            unique evaluating: 3
            unique evaluating: 1
            square evaluating: 1
    consuming: 1
    */
    ```
- 복수의 입력시퀀스를 사용하는 이터레이터 메서드도 있다.
    ```
    static IEnumerable<string> Zip(IEnumerable<string> first, IEnumerable<string> second)
    {
        using (var firstSequence = first.GetEnumerator())
        {
            using (var secondSequence = second.GetEnumerator())
            {
                while (firstSequence.MoveNext() && secondSequence.MoveNext())
                    yield return $"{firstSequence.Current} {secondSequence.Current}";
            }
        }
    }
    ```
- ***See Also***
    - [***C# 1.0 - IEnumerable***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2001.0%20summary.md#4514-interface)
    - [***C# 2.0 - yield return/break***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2002.0%20summary.md#74-yield-returnbreak)
    - [***C# 3.0 - standard query operators***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2003.0%20summary.md#892-standard-query-operators)


　

### 32. Action, Predicate, Function과 순회 방식을 분리하라
---
- LINQ가 내부적으로는 이런 느낌으로 구현되어 있구나... 하고 알아두면 좋겠다.
- 델리게이트를 사용하여 순회 메서드 중간을 커스텀한다.
- BCL 예시
    ```
    myList.RemoveAll(n => n == 5); // Predicate가 사용되었다.
    myList.ForEach(n => Console.WriteLine(n)); //  Action<T>가 사용되었다.
    ```
- 필터 메서드 - Predicate를 이용하여 작성할 수 있다.
    ```
    public static IEnumerable<T> Where<T>(IEnumerable<T> sequence, Predicate<T> filter)
    {
        if (sequence == null)
            throw new ArgumentNullException(nameof(sequence), "sequence must not be null");
    
        if (filter == null)
            throw new ArgumentNullException("Predicate must not be null");
    
        foreach (T item in sequence)
            if (filter(item))
                yield return item;
    }
    ```
- 변환 메서드 - Func를 통해 작성할 수 있다.
    ```
    public static IEnumerable<Tout> Select<Tin, Tout>(IEnumerable<Tin> sequence, Func<Tin, Tout> selector)
    {
        // null 체크 코드 생략
        foreach (Tin element in sequence)
            yield return selector(element);
    }
    ```
- ***See Also***
    - [***C# 3.0 - Action & Func***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2003.0%20summary.md#8811-action--func)


　

### 33. 필요한 시점에 필요한 요소를 생성하라
---
- 새로운 컬렉션을 생성하는 팩토리로 이터레이터 메서드를 사용할 수도 있다.
- 일반 메서드로는 아래와 같이 구현해볼 수 있다.
- 사용하지 않을 숫자까지 전부 생성한다.
    ```
    static IList<int> CreateSequence(int numberOfElements, int startAt, int stepBy)
    {
        var collection = new List<int>(numberOfElements);
        for(int i = 0; i < numberOfElements; i++)
            collection.Add(startAt + i * stepBy);
            
        return collection;
    }
    ```
- 숫자 시퀀스를 생성하면, 사용하지 않을 요소는 생성하지 않을 수 있다.
    ```
    var sequence = CreateSequence(1000, 0, 5).TakeWhile((n) => n < 50);
    
    public static IEnumerable<int> CreateSequence(int numberOfElements, int startAt, int stepBy)
    {
        for (int i = 0; i < numberOfElements; i++)
            yield return startAt + i * stepBy;
    }
    ```


　

### 34. 함수를 매개변수로 사용하여 결합도를 낮추라
---
- 다른 개발자가 사용할 코드를 작성하는 경우 의존성 문제를 코드에서 분리하는 방법
- [AS-IS] 추상 클래스 또는 인터페이스를 상속하는 방식
    ```
    // void List<T>.RemoveAll(Predicate<T> match);
    // 위 메서드를 델리게이트가 아니라 인터페이스를 이용해서 구현한다면...
    
    // 추가적으로 부적절한 연관 관계가 생김
    public interface IPredicate<T>
    {
        bool Match(T target);
    }
    
    public class List<T>
    {
        public void RemoveAll(IPredicate<T> match)
        {
            ...
        }
        ...
    }

    // 이 인터페이스를 사용하려면 추가적인 작업이 필요하다.
    public class MyPredicate : IPredicate<int>
    {
        public bool Match(int target) => target < 100;
    }
    ```
- 추가 작업이 너무 번거롭다. 배보다 배꼽이 크다.
- 개선 - 함수를 매개변수로 취하는 방법
    ```
    List<int> first = new List<int>() { 0, 1, 2, 3 };
    List<string> second = new List<string>() { "A", "B", "C", "D" };
    var result = Zip(first, second, (one, two) => $"{one} {two}");
    
    public static IEnumerable<TResult> Zip<T1, T2, TResult>(
        IEnumerable<T1> first,
        IEnumerable<T2> second,
        Func<T1, T2, TResult> zipper)
    {
        using (var firstSequence = first.GetEnumerator())
        {
            using (var secondSequence = second.GetEnumerator())
            {
                while (firstSequence.MoveNext() && secondSequence.MoveNext())
                    yield return zipper(firstSequence.Current, secondSequence.Current);
            }
        }
    }
    ```


　

### 35. 확장 메서드는 절대 오버로드하지 마라
---
- 타입의 본질적인 동작 방식을 변경하기 위하여 확장 메서드를 사용해서는 안된다.
- 확장 메서드를 여러 네임 스페이스에 걸쳐 오버로드 해서는 안된다.
- 동일한 확장 메서드를 여러 개 만들어야 한다면 이름을 달리하자.
- 확장 메서드를 잘못 사용한 예.
    ```
    public sealed class Person
    {
        public string FirstName
        {
            get; set;
        }
        public string LastName
        {
            get; set;
        }
    }
    
    // 확장 메서드를 이용하여 클래스를 확장함.
    namespace ConsoleExtensions
    {
        public static class ConsoleReport
        {
            public static string Format(this Person target) =>
                $"{target.LastName,20}, {target.FirstName,15}";
        }
    }
    
    // XML 형식으로 출력해야 하는 경우가 생겼다.
    namespace XmlExtensions
    {
        public static class XmlReport
        {
            public static string Format(this Person target) =>
                new XElement("Person",
                    new XElement("LastName", target.LastName),
                    new XElement("FirstName", target.FirstName)).ToString();
        }
    }
    ```
- 이름을 달리하고 일반 정적 메서드로 만드는 게 더 좋다.
    ```
    // 이름을 달리 하라는 건 알겠는데,
    // 이 경우 기능의 확장이라고 보기 어렵기 때문에 애초에 확장 메서드를 쓰는게 옳지 않다고 한다.
    // 솔직히... 아직 잘 이해하지 못하고 있다. ㅠㅠ
    public static class PersonReports
    {
        public static string FormatAsText(Person target) =>
            $"{target.LastName,20}, {target.FirstName,15}";
    
        public static string FormatAsXML(this Person target) =>
            new XElement("Person",
                new XElement("LastName", target.LastName),
                new XElement("FirstName", target.FirstName)).ToString();
    }
    ```
- ***See Also***
    - [***27. 인터페이스는 간략히 정의하고 기능의 확장은 확장 메서드를 사용하라***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Effective%20C%23/%5BEffective%20C%23%5D%2021%20~%2030.md#27-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4%EB%8A%94-%EA%B0%84%EB%9E%B5%ED%9E%88-%EC%A0%95%EC%9D%98%ED%95%98%EA%B3%A0-%EA%B8%B0%EB%8A%A5%EC%9D%98-%ED%99%95%EC%9E%A5%EC%9D%80-%ED%99%95%EC%9E%A5-%EB%A9%94%EC%84%9C%EB%93%9C%EB%A5%BC-%EC%82%AC%EC%9A%A9%ED%95%98%EB%9D%BC)
    - [***28. 확장 메서드를 이용하여 구체화된 제네릭 타입을 개선하라***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Effective%20C%23/%5BEffective%20C%23%5D%2021%20~%2030.md#28-%ED%99%95%EC%9E%A5-%EB%A9%94%EC%84%9C%EB%93%9C%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%98%EC%97%AC-%EA%B5%AC%EC%B2%B4%ED%99%94%EB%90%9C-%EC%A0%9C%EB%84%A4%EB%A6%AD-%ED%83%80%EC%9E%85%EC%9D%84-%EA%B0%9C%EC%84%A0%ED%95%98%EB%9D%BC)


　

### 36. 쿼리 표현식과 메서드 호출 구문이 어떻게 대응되는지 이해하라
---
- C# 컴파일러는 쿼리 언어로 작성된 쿼리 표현식을 메서드 호출 구문으로 변환해준다.
- 테스트 자료
    ```
    var odds = new int[] { 1, 3, 5, 7 };
    var evens = new int[] { 2, 4, 6, 8 };
    var numbers = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    var labels = new string[] { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    var employees = new Employee[]
    {
        new Employee("AAA", "aaa", 10, "A"),
        new Employee("BBB", "bbb", 20, "A"),
        new Employee("EEE", "eee", 50, "C"),
        new Employee("DDD", "ddd", 40, "B"),
        new Employee("CCC", "ccc", 30, "C"),
    };
    record Employee(string FirstName, string LastName, int Age, string Department)
    {
    }
    ```
- Where : 조건 필터
    ```
    var t1 = from n in numbers where n < 5 select n;
    var t2 = numbers.Where(n => n < 5);
    Select : 입력값을 다른 타입으로 변환하는 용도로 사용한다.

    var t1 = from n in numbers select n;
    var t2 = numbers.Select(n => n);
    
    var t3 = from n in numbers where n < 5 select n * n;
    var t4 = numbers.Where(n => n < 5).Select(n => n * n);
    
    var t5 = from n in numbers select new { Number = n, Square = n * n };
    var t6 = numbers.Select(n => new { Number = n, Square = n * n });
    ```
- OrderBy, ThenBy : 입력값을 정렬한다.
    ```
    var t1 = from e in employees
            where e.Age > 10
            orderby e.LastName, e.FirstName, e.Age
            select e;
    
    var t2 = employees
            .Where(e => e.Age > 10)
            .OrderBy(e => e.LastName)
            .ThenBy(e => e.FirstName)
            .ThenBy(e => e.Age);
    ```
- GroupBy : 개별 요소로 하나의 키와 값의 리스트를 쌍으로 갖는 시퀀스를 생성한다.
    ```
    var t1 = from e in employees
            group e by e.Department into d
            select new { Department = d.Key, Size = d.Count() };
    
    var t2 = from d in
            from e in employees group e by e.Department
            select new { Department = d.Key, Size = d.Count() };
    
    var t3 = employees
            .GroupBy(e => e.Department)
            .Select(d => new { Department = d.Key, Size = d.Count() });
    ```
- SelectMany : 여러개의 from 절을 포함하는 쿼리식은 SelectMany 메서드로 변환된다.
    ```
    var t1 = from odd in odds
            from even in evens
            where odd > even
            select new { odd, even, Sum = odd + even };
    
    var t2 = odds
            .SelectMany(odd => evens, (odd, even) => new { odd, even })
            .Where(pair => pair.odd > pair.even)
            .Select(pair => new { pair.odd, pair.even, Sum = pair.odd + pair.even });
    ```
- Join : join 표현식에서 사용된다.
    ```
    var query = from number in numbers
                join label in labels on number.ToString() equals label
                select new { number, label };
    
    var qeury = numbers.Join( // outer
                labels, // inner
                number => number.ToString(), // outer key
                label => label, // inner key
                (number, label) => new { number, label }); // result
    ```
- ***See Also***
    - [***C# 3.0 - LINQ(Language INtegrated Query)***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2003.0%20summary.md#89-linqlanguage-integrated-query)
    - [***C# 3.0 - SelectMany***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2003.0%20summary.md#8921-selectmany)


　

### 37. 쿼리를 사용할 때는 즉시 평가보다 지연 평가가 낫다
---
- 지연 평가 (lazy evaluation)
    > - 쿼리를 정의한다고 해서 결과 데이터나 시퀀스를 즉각적으로 얻어오는 것은 아니다.
    > - 쿼리를 정의하는 작업은 수행 시에 어떤 과정으로 작업을 수행할지에 대한 절차만를 정의하는 것이다.
    > - 일반적으로 이러한 방식이 더 효과적이며 실제로 쿼리의 결과를 이용하여 순회를 수행해야만 결과가 생성된다.
- 지연 평가의 특징을 잘 보여주는 예제
    ```
    internal class Program
    {
        static void Main(string[] args)
        {
            LazyEvaluation();
        }
    
        static void LazyEvaluation()
        {
            Console.WriteLine($"Start time for Test One: {DateTime.Now:T}");
            var sequence = Generate(10, () => DateTime.Now);
    
            Console.WriteLine("Waiting...\tPress Return");
            Console.ReadLine();
    
            Console.WriteLine("Iterating...");
            foreach (var value in sequence)
                Console.WriteLine($"{value:T}");
    
            Console.WriteLine("Waiting...\tPress Return");
            Console.ReadLine();
    
            Console.WriteLine("Iterating...");
            foreach (var value in sequence)
                Console.WriteLine($"{value:T}");
        }
    
        static IEnumerable<TResult> Generate<TResult>(int number, Func<TResult> generator)
        {
            for (int i = 0; i < number; i++)
                yield return generator();
        }
    }
    ```
- 쿼리의 결과를 대상으로 추가적인 쿼리를 수행하는 코드
    ```
    // sequence1과 sequence2는 데이터를 공유하는 것이 아니라 내부적으로 함수를 합성하여 수행된다.
    // sequence2를 순회할 때 sequence1이 이미 생성해둔 값을 순회하면서 개별 요소를 수정하는 것이 아니라,
    // 순회 시점에 맞춰 sequence1이 값을 생성한다.
    var sequence1 = Generate(10, () => DateTime.Now);
    var sequence2 = from value in sequence1 select value.ToUniversalTime();
    ```
- 하지만 일부 쿼리 표현식은 결과를 얻기 위해서 반드시 전체 시퀀스가 필요한 경우가 있다.
- 아래 코드는 where 절이 시퀀스 내의 모든 값을 대상으로 비교 연산을 수행하기 때문에 int.MaxValue까지 순회가 수행된다.
    ```
    internal class Program
    {
        static void Main(string[] args)
        {
            var answers = from number in AllNumbers()
                        where number < 10
                        select number;
    
            foreach (var num in answers)
                Console.WriteLine(num);
        }
    
        static IEnumerable<int> AllNumbers()
        {
            var number = 0;
            while (number < int.MaxValue)
                yield return number++;
        }
    }
    ```
- where, orderby, Max, Min은 전체 시퀀스를 요구한다. 시퀀스가 무한정 지속될 가능성이 있다면 이 같은 메서드는 사용하면 안된다.
- 또한 필터링은 다른 쿼리보다 먼저 수행하는 것이 좋다.
- 아래 두 쿼리는 동일한 결과를 생성하지만 두 번째 쿼리가 첫 번째 쿼리보다 더 빠르다.
    ```
    // 정렬 후 필터링
    var sortedProjuctsSlow = from p in products
                            orderby p.UnitsInStock descending
                            where p.UnitsInStock > 100
                            select p;
                            
    // 필터링 후 정렬
    var sortedProjuctsFast = from p in products
                            where p.UnitsInStock > 100
                            orderby p.UnitsInStock descending
                            select p;
    ```
- ***See Also***
    - [***C# 3.0 - standard query operators***](https://github.com/icodes-studio/wiki/blob/main/STUDY%2BRND/Begining%20C%23/%5BC%23%5D%2003.0%20summary.md#892-standard-query-operators)


　

### 38. 메서드보다 람다 표현식이 낫다
---
- 람다 표현식을 이용하여 코드를 작성하다 보면 동일한 코드를 반복하는 경우가 자주 발생한다.
    ```
    var employees = FindAllEmployees();
    
    // 20년 이상 근속자 중 낮은 월급쟁이들
    var earlyFolks = from employee in employees
                    where employee.Classification == EmployeeType.Salary
                    where employee.MonthlySalary < 4000
                    where employee.YearsOfService >= 20
                    select employee;
    
    // 20년 미만 근속자 중 낮은 월급쟁이들
    var newest     = from employee in employees
                    where employee.Classification == EmployeeType.Salary
                    where employee.MonthlySalary < 4000
                    where employee.YearsOfService < 20
                    select employee;
    ```
- 동일한 람다 표현식이 반복 사용되는 것을 방지하기 위해서 재사용 가능한 메서드를 정의해 이용할 수도 있다.
    ```
    // 공통 부분을 메서드로 분리
    private static bool LowPaidSalaried(Employee employee) =>
        employee.Classification == EmployeeType.Salary && employee.MonthlySalary < 4000;
    
    // 20년 이상 근속자
    var employees = FindAllEmployees();
    var earlyFolks = from employee in employees
                    where LowPaidSalaried(employee) && employee.YearsOfService >= 20
                    select employee;
    
    // 20년 미만 근속자
    var employees = FindAllEmployees();
    var earlyFolks = from employee in employees
                    where LowPaidSalaried(employee) && employee.YearsOfService < 20
                    select employee;
    ```
- 하지만 메서드로 분리한 부분은 재사용 가능성이 낮다.
- 오히려 첫 번째 코드가 람다 표현식이 평가되고, 파싱되고, 수행되는 일련의 과정 때문에 재사용 가능성이 높다.
- 메서드로 공통 코드를 분리하면 코드가 더 간단해진다고 생각할 수 있지만, 통상 쿼리 표현식 내 람다 표현식은 델리게이트로 변환되어 수행하기 때문에 틀린 말이 된다.
- LINQ to SQL의 경우 T-SQL 구문이란 것으로 변경하는 과정이 있는데 메서드 호출부를 나타내는 노드를 T-SQL 표현식으로 변경하지 못하는 문제가 있다. (뭐래... 어려워 ㅠㅠ)
- 암튼, 쿼리 표현식과 람다가 관련된 경우에 한하여 기존 방식과는 조금 다른 형태의 빌딩 블록을 만들어서 사용해야 한다.
    ```
    private static IQueryable<Employee> LowPaidSalariedFilter(this IQueryable<Employee> sequence) =>
        from s in sequence
        where s.Classification == EmployeeType.Salary && s.MonthlySalary < 4000
        select s;
    
    // 우선 필터링을 수행 함
    var employees = FindAllEmployees();
    var salaried = employees.LowPaidSalariedFilter();
    
    // 20년 이상 근속자
    var earlyFolks = salaried.Where(employee => employee.YearsOfService >= 20);
    
    // 20년 미만 근속자
    var newest = salaried.Where(employee => employee.YearsOfService < 20);
    ```


　

### 39. function과 action 내에서는 예외가 발생하지 않도록 하라
---
- 일련의 값을 순차 처리하는 코드에서 중간지점에서 오류가 난다면 예외 발생 지점을 파악하기 어렵다.
- 특히나 시퀀스 내 요소의 값을 직접 수정하는 경우 루틴 수행 이전으로 원복 하기는 매우 어렵다.
- 방어 코드는 예상 가능한 오류에 대해서만 처리가 가능하다.
- 예외가 발생하지 않도록 작성하는 것이 불가능한 경우라면... 
- 원본 시퀀스의 복사본으로 알고리즘을 수행하고 정상 완료된 경우에 시퀀스를 대체하는 방법이 있다.
    ```
    var updates =
    (
        from employ in employees
        select new Employee
        {
            ID = employ.ID,
            Classification = employ.Classification,
            YearsOfService = employ.YearsOfService,
            MonthlySalary = employ.MonthlySalary *= 1.05M
        }
    ).ToList();
    
    employees = updates;
    ```


　

### 40. 지연 수행과 즉시 수행을 구분하라
---
- 명령형 코드(Imperative Code)
    > - 데이터 기반
    > - 어떻게 작업을 수행해야 하는지를 단계별로 세분화하여 기술한다.
    > - 필요한 매개변수를 모두 계산한 다음에야 비로소 메서드를 호출한다.
    > - 메서드를 호출하고 그 결과를 다른 메서드에 전달한다.
    ```
    var answer = DoStuff(Method1(), Method2(), Method3());
    ```
- 선언적 코드(Declarative Code)
    > - 메서드 기반
    > - 무슨 작업을 해야 하는지를 정의한다.
    > - 각 메서드의 수행 결과가 필요한 경우에만 호출된다.
    > - 델리게이트를 매개변수로 전달한다.
    > - 아래 코드에서 Method1, 2, 3는 어떤 순서로도 수행될 수 있으며 필요한 경우 여러번 수행되거나, 전혀 수행되지 않을 수도 있다.
    ```
    var answer = DoStuff(() => Method1(), () => Method2(), () => Method3());
    ```
- 즉시수행과 지연수행
    > - 즉시 수행과 지연 수행은 다르게 동작하며 결과가 다를 수 있다.
    > - 즉시 수행과 지연 수행이 같은 결과를 얻기 위해서는 매개변수와 메서드가 변경 불가해야 한다.
    > - 즉시 수행과 지연 수행이 같은 결과를 반환한다고 했을 때에 어떤 것을 선택해야 할까?
    > - Math.PI, 파이 값을 매번 계산하는 것 보다 저장해두고 쓰는 것이 더 효율적일 것이다.
    > - CalculatePrimeFactors(int), 모든 정수의 약수를 저장해두기 보다는 매번 계산하는 편이 효율적일 것이다.
    > - 혹은 두가지 방법을 혼합해서 사용하는 방법도 있다.
    ```
    var cache = Method1();
    var answer = DoStuff(() => cache, () => Method2(), () => Method3());
    ```
