### 21. 타입 매개변수가 IDisposable을 구현한 경우를 대비하여 제네릭 클래스를 작성하라
---
- 제네릭 클래스의 타입 매개변수로 객체를 생성하는 경우, 이 타입이 IDisposable을 구현하고 있는지 확인하고 적절히 처리하자.
```
public interface IEngine
{
    void DoWork();
}
 
public class EngineDriverOne<T> where T : IEngine, new()
{
    public void GetThingsDone()
    {
        T driver = new T();
        using (driver as IDisposable)
        driver.Dowork();
    }
}
```

### 22. 공변성과 반공변성을 지원하라
---
- 공변 (Covariance)
    - X → Y가 가능할 때, C<T>가 C<X> → C(Y)로 가능하다면
- 반공변 (Contravariance)
    - X → Y가 가능할 때, C<T>가 C<Y> → C(X)로 가능하다면
- 불변성 (Invariance)
    - 공변성과 반공변성은 가변성(variance)라고 부르는데 그의 반대.
- 제네릭타입은 기본적으로 불변성이기 때문에 class C<T>가 정의되어 있더라도 C<Base>에 C<Derived>를 할당할 수 없다.
- 하지만 C#의 대표적인 IEnumerable<T>는 IEnumerable<Base>변수에 IEnumerable<Derived>인스턴스를 할당할 수 있는데 그 이유는 IEnumerable이 공변적(<out T>)으로 지정되었기 때문이다.
```
// object를 상속하는 자식 객체 string 이 object 부모 변수에 할당됩니다.
IEnumerable<string> strings = new List<string>();
IEnumerable<object> objects = strings;
 
// 반환타입이 object 로 string 의 부모인 대리자에 반환타입이 string 으로 obejct의 자식인 함수를 할당합니다.
static string GetString() { return ""; }
Func<object> del = GetString;
```
- 반대로 부모 객체가 자식 변수로 할당되는 형변환 키워드는 in
```
static void SetObject(object o) { }
Action<object> actObject = SetObject;
Action<string> actString = actObject;
```
- ***See Also***
    - ***C# 9.0 - covariant return types***
    - ***https://youtu.be/v5op4r6AojI***
    - ***https://ibocon.tistory.com/91***
    - ***https://sticky32.tistory.com/entry/C-%EA%B3%B5%EB%B3%80%EC%84%B1%EA%B3%BC-%EB%B0%98%EA%B3%B5%EB%B3%80%EC%84%B1%EC%9D%B4%EB%9E%80***
    - ***https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/covariance-contravariance/***

### 23. 타입 매개변수에 대해 메서드 제약 조건을 설정하려면 델리게이트를 활용하라
---
- 인터페이스를 이용한 메서드 제약
    - Add() 메서드를 정의하는 IAdd 인터페이스를 생성한다.
    - IAdd 인터페이스로 제약 조건을 설정한다.
    - IAdd를 구현할 클래스를 생성하고 구현한다.
    - 번거롭다.
- 델리게이크를 이용한 메서드 제약
- 제약조건으로 설정하고 싶은 메서드에 부합하는 델리게이트를 작성하고 이를 델리게이트 타입 T로 정의한다.
- 활용 예
```
class Program
{
    static void Main()
    {
        int left = 10;
        int right = 20;
        int sum = Example.Add(left, right, (left, right) => left + right);
        int minus = Example.Minus(left, right, (left, right) => left - right);
        Console.WriteLine($"Sum: {sum}");
        Console.WriteLine($"Minus: {minus}");
    }
}
 
public static class Example
{
    public static T Add<T>(T left, T right, Func<T, T, T> AddFunc) => AddFunc(left, right);
    public static T Minus<T>(T left, T right, Func<T, T, T> MinusFunc) => MinusFunc(left, right);
}
```

### 24. 베이스 클래스나 인터페이스에 대해서 제네릭을 특화하지 말라
---
- 아래 코드의 출력은 어떻게 될까?
```
public abstract class Parent
{
    public double Mass { get; set; }
    public string Name { get; set; }
}
 
public class DerivedA : Parent
{
}
 
public class MyTest
{
    public void MyMethod()
    {
        DerivedA a = new DerivedA();
        Print(a);
    }
 
    public void Print<T>(T p)
    {
        Debug.Log("제네릭 T");
    }
 
    public void Print(Parent p)
    {
        Debug.Log("부모");
    }
}
```
- 정답: "제네릭 T"
- "부모"를 출력하게 하고 싶으면 Parent로 명시적 캐스팅 해야 한다.
- 즉, 베이스 클래스에 대해서 제네릭을 특화하려고 시도해봤자 T가 우선권을 가져가기 때문에 의미가 없다는 소리.
- 타입이 몇 개 없다면 차라리 런타임 중에 타입을 is로 확인하여 분기시키는 게 나을 수도 있다.
- 특화를 할 거라면 해당 타입 뿐 아니라 이 타입을 상속한 모든 파생 타입에 대해서도 특화를 수행해야 한다.

### 25. 타입 매개변수로 인스턴스 필드를 만들 필요가 없다면 제네릭 메서드를 정의하라
---
- 무작정 제네릭 클래스를 만드는 것 보다는 일반 클래스 내의 제네릭 메서드를 작성하는 편이 훨씬 좋은 경우가 있다.
- 제네릭 클래스는 클래스 전체를 하나의 제약조건으로 감싸게 되지만
- 일반 클래스 내의 제네릭 메서드는 각 메서드마다 개별적인 제약 조건을 설정할 수 있다.
- 제네릭 클래스의 메서드 호출 시마다 매번 타입 매개변수를 명시적으로 지정해야 하는 불편함도 있다.

### 26. 제네릭 인터페이스와 논제네릭 인터페이스를 함께 구현하라
---
- 제네릭이 없던 시절에 개발된 코드들을 지원해야 한다.
- 명시적 방법으로 구현
```
public class Name : IComparable<Name>, IComparable
{
    public string First { get; set; }
    public string Last { get; set; }
    public string Middle { get; set; }
 
    public int CompareTo(Name other)
    {
        if (Object.ReferenceEquals(this, other))
            return 0;
        if (Object.ReferenceEquals(other, null))
            return 1;
 
        int result = Comparer<string>.Default.Compare(Last, other.Last);
        if (result != 0)
            return result;
 
        result = Comparer<string>.Default.Compare(First, other.First);
        if (result != 0)
            return result;
 
        return Comparer<string>.Default.Compare(Middle, other.Middle);
    }
 
    int IComparable.CompareTo(object obj)
    {
        // Name의 파생 클래스를 필터링 하기 위해서
        if (obj.GetType() != typeof(Name))
            throw new ArgumentException("Argument is not a Name object");
        return this.CompareTo(obj as Name);
    }
}
```
- 논제네릭을 명시적으로 구현한다면 암시적으로 구현된 제네릭 메서드가 우선적으로 선택되기 때문에 실수로 논제네릭을 사용하는 일을 방지할 수 있다.
- 참고: 명시적으로 구현된 인터페이스 메서드는 해당 인터페이스의 참조를 통해서만 호출할 수 있다.
- ***See Also***
    - ***C# 1.0 - interface***

### 27. 인터페이스는 간략히 정의하고 기능의 확장은 확장 메서드를 사용하라
---
- 확장 메서드를 이용하면 인터페이스의 기능을 손쉽게 확장할 수 있다.
- System.Linq.Enumerable 클래스가 대표적인 예로, Where, OrderBy, ThenBy, GroupInfo 등은 확장 메서드로 구현되어있다.
- 기존(또는 새로 만들) 구현체에 확장 기능을 넣으려고 수정할 필요가 없다.
- 새로운 메서드를 추가하기 이전에, 이미 정의되어 있는 다른 메서드를 이용하여 구현 가능한 기능인지를 확인해보자.
- 만약 기존 멤버를 이용하여 구현 가능한 메서드라면 확장 메서드로 구현할 수 있는 좋은 후보가 된다.

### 28. 확장 메서드를 이용하여 구체화된 제네릭 타입을 개선하라
---
- 기능을 추가할 때 구체화된 제네릭 필드를 상속하여 메서드를 추가하기 보다는 확장메서드를 구현하는 것을 고려하자.
- 뭔 말이냐면, 아래 코드처럼 상속 받아서 새로운 기능을 추가하지 말고
```
public class CustomerList : List<Customer>
{
    public void SendEmailCoupons(Coupon specialOffer)
    {
        //...
    }
}
```
- 구체화된 컬렉션 타입에 대해 확장 메서드를 작성하자.
```
public static void SendEmailCoupons(this IEnumerable<Customer> customers, Coupon specialOffer)
{
    //...
}
```

### 29. 컬렉션을 반환하기보다 이터레이터를 반환하는 것이 낫다
- 이터레이터란 호출자가 요청한 시퀀스를 생성하기 위해서 사용하는 Enumerable / Enumerator를 의미한다.
- Enumerable.Range()를 사용하는 경우를 생각해보자 
```
IEnumerable<int> allNumbers = Enumerable.Range(0, int.MaxValue);
```
- Range 메서드를 호출하면 일련의 숫자 컬렉션이 아니라 숫자 시퀀스를 만들어내는 객체를 생성한다.
- 호출 측에서는 이터레이터 메서드의 결과 값을 추가적인 컬렉션에 저장하지 않는 이상 방대한 결과치를 저장하기 위한 공간이 필요없다.
- '필요할 때 생성' 이라는 전략은 이터레이터 메서드를 작성할 때 가장 중요한 전략 중 하나이다.
- ***See Also***
    - ***IEnumerable / IEnumerator***
    - ***yield return/break 사용하여 열거하기***

### 30. 루프보다 쿼리 구문이 낫다
---
- 쿼리 구문의 장점
    - 프로그램의 논리를 명령형 방식에서 선언적인 방식으로 전환할 수 있다.
    - 질의의 내용을 구성할 수 있을 뿐 아니라 개별 항목에 대해 수행하려는 작업의 수행 시기를 연기할 수 있다.
    - 사용자의 의도를 더 명확하게 드러낼 수 있다.
- 예시: (0, 0)에서 떨어진 거리 순으로 정렬하여 객체를 반환
```
// 루프 방식
private static IEnumerable<Tuple<int, int>> ProduceIndices3()
{
    var storage = new List<Tuple<int, int>>();
    for (var x = 0; x < 100; x++)
        for (var y = 0; x < 100; y++)
            storage.Add(Tuple.Create(x, y));
 
    storage.Sort((point1, point2) =>
        (point2.Item1 * point2.Item1 + point2.Item2 * point2.Item2).CompareTo
        (point1.Item1 * point1.Item1 + point1.Item2 * point1.Item2));
 
    return storage;
}
 
// 쿼리구문 방식
private static IEnumerable<Tuple<int, int>> QueryIndices3()
{
    return  from x in Enumerable.Range(0, 100)
            from y in Enumerable.Range(0, 100)
            orderby(x * x + y * y) descending
            select Tuple.Create(x, y);
}
```
- ***See Also***
    - ***C# 3.0 - LINQ(Language INtegrated Query)***
