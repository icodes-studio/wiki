### 11. .NET 리소스 관리에 대해 이해하라.
---
- 힙에 관한 메모리 관리는 가비지 컬렉터가 완전히 책임진다.
- 가비지 컬렉터의 세대 개념
    > - 0세대: 처음 할당되는 객체들
    > - 1세대: 첫 번째 수집 절차에서 살아남은 객체들
    > - 2세대: 두번 혹은 그 이상의 수집 절차에서 살아남은 객체들
- 수집 절차
    > - 기본적으로 0세대 객체만 검사
    > - 1세대는 대략 10번에 한 번 검사
    > - 2세대는 대략 100번에 한 번 검사
- 이 외의 비관리 리소스는 개발자가 관리해야한다.
- 비관리 리소스는 Finalizer 와 IDisposable인터페이스라는 두가지 메커니즘 제공한다.
- 하지만, Finalizer를 포함하고 있는 객체는 Finalizer를 호출하기 위해 종료 큐에 임시 저장되어 바로 가비지 컬렉트 되지 않는다.
- 또한 언제 Finalize 될지 알 수도 없다. 그래서…
- 비관리 리소스를 안전하게 해제하는 좋은 방법.
    ```
    using System.Threading;
    using System.Diagnostics;
    using System.Runtime.InteropServices;
    
    class UnmanagedMemoryManager : IDisposable
    {
        private IntPtr buffer;
        private bool disposed;
        protected virtual void OnDispose(bool disposing)
        {
            if (false == disposed)
            {
                Marshal.FreeCoTaskMem(buffer);
                disposed = true;
            }
    
            if (true == disposing)
            {
                // 종료 큐에서 자신을 제거해 GC의 부담을 줄인다.
                GC.SuppressFinalize(this);
            }
        }
        public void Dispose()
        {
            OnDispose(true);
        }
        public UnmanagedMemoryManager()
        {
            buffer = Marshal.AllocCoTaskMem(4096 * 1024);
        }
        ~UnmanagedMemoryManager()
        {
            OnDispose(false);
        }
        public static void Main()
        {
            while (true)
            {
                // 메모리 해제 확인
                using (var m = new UnmanagedMemoryManager())
                {
                    Thread.Sleep(1000);
                }
                Console.WriteLine(Process.GetCurrentProcess().PrivateMemorySize64);
            }
        }
    }
    ```
- ***See Also***
    - ***C# 1.0 - heap & stack***
‌

　

### 12. 할당 구문보다 멤버 초기화 구문이 좋다.
---
- 새로운 생성자를 추가하더라도 별도로 초기화할 필요가 없다.
- 베이스 클래스 생성자가 호출되기 전에 멤버에 대한 초기화가 이루어진다.
- 두 번 이상 할당하는 꼴이 되는 경우는 사용하지 말자.
- 0이나 null로 초기화 되는 경우는 사용하지 말자.
- 예외 처리가 필요하다면 생성자 내에서 처리하자.
- ***See Also***
    - ***C# 6.0 - initializers for auto-properties***
‌

　

### 13. 정적 클래스 멤버를 올바르게 초기화하라.
---
- 인스턴스를 생성하기 전에 반드시 정적 멤버 변수(있다면)를 초기화 해야 한다.
    > - 정적 멤버 초기화 구문 이용 초기화
    > - 정적 생성자 이용 초기화
- 정적 생성자에서 예외가 발생하면 죴땐다. 주의하라.


　

### 14. 초기화 코드가 중복되는 것을 최소화하라.
---
- 여러 생성자 내에서 동일한 코드를 반복적으로 사용해야 한다면…
- 공용 초기화 헬퍼 함수를 만들어 사용하지 말고!
- 공용으로 사용할 수 있는 생성자를 작성하는 편이 낫다.
    > - 이렇게 하면 C# 컴파일러는…
    > - 변수에 대한 중복 초기화 코드를 제거해 준다.
    > - 베이스 생성자 호출 코드가 반복적으로 확장 되는 것도 막아준다.
    > - readonly, init 등의 immutable 변수도 초기화 가능하다.
- 예제 코드
    ```
    public class MyClass
    {
        private List<int> collection;
        private readonly string name;
    
        public MyClass() :
            this(0, string.Empty)
        {
        }
        public MyClass(int initalCount = 0, string name = "")
        {
            collection = (initalCount > 0) ?
                new List<int>(initalCount) :
                new List<int>();
            this.name = name;
        }
    }
    ```


　

### 15. 불필요한 객체를 만들지 말라.
---
- 자주 생성되는 객체의 경우 클래스 멤버로 관리하거나…
- 아래처럼 캐싱 기법을 사용하자.
    ```
    private static Brush blackBrush;
    public static Brush Black
    {
        get
        {
            if (blackBrush == null)
                blackBrush = new SolidBrush(Color.Black);
            return blackBrush;
        }
    }
    ```


　

### 16. 생성자 내에서는 절대로 가상 함수를 호출하지 말라.
---
- 객체가 완전히 생성되기전 가상 함수를 호출하면 이상동작(?)이 발생한다.
- 아래 코드는 어떤 문자열을 출력할까?
    ```
    class B
    {
        protected B()
        {
            VFunc();
        }
        protected virtual void VFunc()
        {
            Console.WriteLine("VFunc in B");
        }
    }
    class Derived : B
    {
        private readonly string msg = "Set by initializer";
        public Derived(string msg)
        {
            this.msg = msg;
        }
        protected override void VFunc()
        {
            Console.WriteLine(msg);
        }
        public static void Main()
        {
            var derived = new Derived("Constructed in main");
        }
    }
    ```


　

### 17. 표준 Dispose 패턴을 구현하라.
---
- 비관리 리소스를 포함하고 있다면 반드시 finalizer를 구현하라.
- 반대로 비관리 리소스가 없을 경우, finalizer를 절대로 추가하지 마라.
- Dispose 메서드 내에서는 리소스 정리작업만 수행하라.
- 비관리 리소스를 안전하게 해제하는 좋은 방법.
    ```
    using System.Threading;
    using System.Diagnostics;
    using System.Runtime.InteropServices;
    
    class UnmanagedMemoryManager : IDisposable
    {
        private IntPtr buffer;
        private bool disposed;
        protected virtual void OnDispose(bool disposing)
        {
            if (false == disposed)
            {
                Marshal.FreeCoTaskMem(buffer);
                disposed = true;
            }
    
            if (true == disposing)
            {
                // 종료 큐에서 자신을 제거해 GC의 부담을 줄인다.
                GC.SuppressFinalize(this);
            }
        }
        public void Dispose()
        {
            OnDispose(true);
        }
        public UnmanagedMemoryManager()
        {
            buffer = Marshal.AllocCoTaskMem(4096 * 1024);
        }
        ~UnmanagedMemoryManager()
        {
            OnDispose(false);
        }
        public static void Main()
        {
            while (true)
            {
                // 메모리 해제 확인
                using (var m = new UnmanagedMemoryManager())
                {
                    Thread.Sleep(1000);
                }
                Console.WriteLine(Process.GetCurrentProcess().PrivateMemorySize64);
            }
        }
    }
    ```
- ***See Also***
    - ***C# 1.0 - Finalizer***
‌

　

### 18. 반드시 필요한 제약 조건만 설정하라.
---
- 너무 많은 제약 조건을 설정하면...
    > - 이를 사용하기 위해 과도한 추가 작업이 필요할 수도 있다.
    > - 사용하기 부담스러워진다.
- 제약 조건이 너무 없으면...
    > - 런타임에 더 많은 검사와 형변환을 수행해야 한다.
    > - 리플렉션을 사용해야 할 가능성이 커진다.
    > - 잘못된 타입으로 인해 런타임 오류가 발생할 가능성이 높아진다.
- 제약 조건을 적절히 잘 사용하면...
    > - 런타임에 발생할 가능성이 있는 오류를 컴파일타임에 확인할 수 있다.
    > - 코드가 간결해 진다.
    > - 값 타입의 경우 박싱과 언박싱을 피할 수 있다.
    > - 가상함수 호출 오버헤드를 피할 수 있다.

- 제약 조건 활용 예 - 코드가 간결하다.
    ```
    public static bool AreEqual<T>(T left, T right) where T : IComparable<T> => left.CompareTo(right) == 0;
    ```
- 제약 조건 없이 런타임으로 타입을 확인하는 경우
    ```
    public static bool AreEqual<T>(T left, T right)
    {
        if (left == null)
            return right == null;
    
        if (left is IComparable<T> lval)
        {
            if (right is IComparable<T>)
                return lval.CompareTo(right) == 0;
            else
                throw new ArgumentException("Type does not implement IComparable<T>", nameof(right));
        }
        else
        {
            throw new ArgumentException("Type does not implement IComparable<T>", nameof(left));
        }
    }
    ```
- 제약 조건을 최소화하는 방법
    > - 제네릭 타입 내에서 반드시 필요한 기능만 제약 조건으로 설정하기
    > - 런타임에 특정 인터페이스나 특정 베이스 클래스를 상속한 타입인지 확인 후 사용하기.
    > - 우선 개선된 메서드를 사용하려 시도해보고, 불가능한 경우에는 한 단계 낮은 수준의 메서드를 사용하기.
    > - 이를 위해, 기본 기능을 제공하는 메서드 외에 자체적으로 구현한 메서드 오버로드하기.
- new 제약조건에 관하여...
    > - new 대신 default()를 사용하면 new() 제약 조건이 필요 없을 수도 있다.
    > - default() 연산자는 특정 타입의 기본 값을 가져온다. 값 타입일 경우에는 0을, 참조 타입일 경우에는 null을 가져온다.
    > - 기본생성자 new T()를 반드시 호출해야 하는 경우가 아니면 default()를 적절히 활용하여 new() 제약 조건을 사용하지 않는 것이 좋다.
- ***See Also***
    - ***C# 2.0 - generic type constraint***


　

### 19. 런타임에 타입을 확인하여 최적의 알고리즘을 사용하라.
---
- 제네릭을 활용하면 코드를 덜 작성해도 되기 때문에 매우 유용하지만 타입이나 메서드를 제네릭화하면 구체적인 타입이 주는 장점을 잃고 타입의 세부적인 특징을 고려한 최적화한 알고리즘도 사용할 수 없다.
- 그래서 만약 어떤 알고리즘이 특정 타입에 대해 더 효율적으로 동작한다고 생각된다면 그냥 그 타입을 이용하도록 작성하는 것도 좋다. 제약 조건을 설정하는 방법도 있지만 제약 조건이 항상 능사는 아니다.
- ILIst\<T\>를 복제하는 최적화 되지 않은 코드
    ```
    public sealed class ReverseEnumerable<T> : IEnumerable<T>
    {
        private IEnumerable<T> source;
        private IList<T> copy;
        public ReverseEnumerable(IEnumerable<T> sequence)
        {
            source = sequence;
        }
        public IEnumerator<T> GetEnumerator()
        {
            if (null == copy)
            {
                // IList<T>를 복제하는 최적화 되지 않은 코드
                copy = source.ToList();
            }
            return new ReverseEnumerator(copy);
        }
        IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();
    
        private class ReverseEnumerator : IEnumerator<T>
        {
            private int index;
            private IList<T> collection;
            public ReverseEnumerator(IList<T> source)
            {
                collection = source;
                index = collection.Count;
            }
            public void Dispose()
            {
            }
            public T Current => collection[index];
            object IEnumerator.Current => this.Current;
            public bool MoveNext() => --index >= 0;
            public void Reset() => index = collection.Count;
        }
    }
    ```
- 타입 확인하는 효율적인 코드로 개선 (생성자 변경)
    ```
    ...
        public ReverseEnumerable(IEnumerable<T> sequence)
        {
            source = sequence;
            copy = sequence as IList<T>;
        }
    ...
    ```
- string, ICollection\<T\> 최적화
    - ...


　

### 20. IComparable\<T\>와 IComparer\<T\>를 이용하여 객체의 선후 관계를 정의하라
---
- IComoparable과 IComparer는 타입에 선후 관계를 제공하기 위한 표준 메커니즘이다.
- 기본적인 선후 관계는 IComparable을 통해 구현한다.
- IComparable을 구현할 때는 관계 연산자도 함께 오버 로딩해서 일관된 결과를 제공해야 한다.
- IComparable.CompareTo()는 System.Object 타입의 매개변수를 취하므로 별도로 오버 로딩된 메서드를 제공해야 한다.
- 별도로 IComparer를 이용하면 추가적인 선후 관계를 정의할 수 있다.
    ```
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    
    public struct Customer : IComparable<Customer>, IComparable
    {
        private readonly string name;
        private double revenue;
        public Customer(string name, double revenue)
        {
            this.name = name;
            this.revenue = revenue;
        }
        public int CompareTo(Customer other) => name.CompareTo(other.name);
        int IComparable.CompareTo(object obj)
        {
            if (obj is Customer other)
                return this.CompareTo(other);
            else
                throw new ArgumentException($"Argument is not a {nameof(Customer)}", nameof(obj));
        }
    
        public static bool operator <(Customer lhs, Customer rhs) => lhs.CompareTo(rhs) < 0;
        public static bool operator <=(Customer lhs, Customer rhs) => lhs.CompareTo(rhs) <= 0;
        public static bool operator >(Customer lhs, Customer rhs) => lhs.CompareTo(rhs) > 0;
        public static bool operator >=(Customer lhs, Customer rhs) => lhs.CompareTo(rhs) >= 0;
    
        private static Lazy<RevenueComparer> revComp = new Lazy<RevenueComparer>(() => new RevenueComparer());
        public static IComparer<Customer> RevenueCompare => revComp.Value;
        public static Comparison<Customer> CompareByRevenue => (left, right) => left.revenue.CompareTo(right.revenue);
    
        private class RevenueComparer : IComparer<Customer>
        {
            int IComparer<Customer>.Compare(Customer lhs, Customer rhs) => lhs.revenue.CompareTo(rhs.revenue);
        }
    
        static void Main()
        {
            Customer a = new Customer("1", 1);
            Customer b = new Customer("2", 2);
            int c = a.CompareTo(b);
            int d = Customer.RevenueCompare.Compare(a, b);
            int e = Customer.CompareByRevenue(a, b);
            Console.WriteLine($"{c}, {d}, {e}")
        }
    }
    ```