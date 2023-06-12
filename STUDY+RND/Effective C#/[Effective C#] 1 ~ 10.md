### 1. 지역변수를 선언할 때는 var를 사용하는 것이 낫다.
---
- var는 실수를 줄여준다.
- 내장 숫자 타입은 그냥 쓰자. 형 변환으로 인한 정밀도 손실 문제를 가져올 수 있다.
- 타입을 애매하게 만들거나 가독성이 떨어지면 쓰지 말자.
- ***See Also***
    - ***C# 3.0 - var keyword***


　

### 2. const 보다는 readonly 가 좋다.
---
- readonly는 유연하다.
- 상수 값이 업데이트 되면 참조하는 모든 코드는 반드시 재컴파일 해야한다. 하지만 readonly는 그럴 필요가 없다.
- 성능이 중요하고, 값이 절대 바뀌지 않는 경우가 아니라면…


　

### 3. 캐스트보다는 is, as가 좋다.
---
- as는 런타임에 더 효율적이고 안전하게 동작한다.
- 비싼 InvalidCastException 예외처리를 사용하지 않는다.
- ***See Also***
    - ***C# 7.0 - is pattern matching***


　
‌
### 4. string.Format()을 보간 문자열로 대체하라.
---
- 코드 가독성이 대폭 향상된다.
- 정적 타입 검사를 수행하기 때문에 개발자의 실수를 미연에 방지한다.
- 문자열을 생성하기 위한 표현식이 더 풍성하다.
```
// 앞에 $를 붙이고 표현식을 {}안에 둔다.
Console.WriteLine($"The value of pi is {Math.PI}");
 
// 원하는 포매팅을 위한 추가적 인자 전달
Console.WriteLine($"The value of pi is {Math.PI.ToString("F2")}");
 
// :을 이용해도 가능
Console.WriteLine($"The value of pi is {Math.PI:F2}");
 
// @를 넣고 ()를 사용해 ':' 가 조건연산자임을 알려줄 수 있다..
Console.WriteLine($@"THe value of pi is {(round ?
    Math.PI.ToString() : Math.PI.ToString("F2"))}");
 
// ?. 연산자와 ?? 연산자도 사용가능!
Console.WriteLine($"The customer's name is {c?.Name ?? "Name is missing"}");
 
// 전달할 인자를 사전에 문자열로 변경하면 값 타입이 박싱되는 것을 피할 수 있다.
Console.WriteLine($"The value of PI is {Math.PI.ToString()}");
```
- ***See Also***
    - ***C# 6.0 - string interpolation***
    - ***C# 11 - Allow new-lines in all interpolations***


　

### 5. 문화권 별로 다른 문자열을 생성하려면 FormattableString을 사용하라.
---
- 문자열 보간을 사용하여 문자열을 만들면 반환값이 문자열일수도, FormattableString을 상속한 타입일 수도 있다.
- FormattableString을 사용하면 현재 컴퓨터에 지정된 문화권을 고려하여 문자열을 생성할 수 있다.
```
class Program
{
    static void Main(string[] args)
    {
        FormattableString fs = $"{Math.PI}";
        Console.WriteLine(fs);
        Console.WriteLine(ToGerman(fs));
    }
 
    public static string ToGerman(FormattableString src)
    {
        return string.Format(
            CultureInfo.CreateSpecificCulture("de-de"),
            src.Format,
            src.GetArgument(0));
    }
}
 
/* 출력결과
3.141592653589793
3,141592653589793
*/
```


　

### 6. nameof() 연산자를 적극 활용하라.
---
- 로컬 심볼 이름을 문자열로 반환하는 역할을 수행한다.
- 심볼의 이름을 바꾸거나 수정할때 실수를 줄일 수 있다.
- ***See Also***
    - ***C# 6.0 - nameof operator***
‌

　

### 7. 델리게이트를 이용하여 콜백을 표현하라.
--- 
- 타입 안정적이고 인터페이스 콜백 보다 효율적이다.
- 자주 사용되는 델리게이트 정의 : Predicate<T>, Acton<T>, Func<T>
- 멀티 캐스트가 가능하다.
- ***See Also:***
    - ***C# 1.0 - delegate***
    - ***C# 3.0 - Action & Func***
‌

　

### 8. 이벤트 호출 시에는 null 조건 연산자를 사용하라.
---    
- 멀티 쓰레드 환경에서 효율적인 코드를 만들어 낸다.
```
public void RaiseUpdates()
{
    counter++;
    if(Updated != null)
    {
        // 이 타이밍에 다른 스레드에서 이벤트 핸들러 등록을 취소 할경우 NullReferenceException이 발생.
        Updated(this, counter);
    }
}
 
// 가독성 떨어지는 방어코드 - 동작하긴 한다.
public void RaiseUpdates()
{
    counter++;
    var handler = Updated;
    if (handler != null)
        handler(this, counter);
}
 
// 멀티스레딩 환경에도 안전한 아름다운 코드
public void RaiseUpdates()
{
    counter++;
    Updated?.Invoke(this, counter);
}
```
- ***See Also***
    - ***C# 1.0 - event***
    - ***C# 6.0 - null conditional operator***
‌

　

### 9. 박싱과 언박싱을 최소화하라.
---
- 박싱은 값 타입을 참조 타입으로 변경한다.
- 박싱과 언박싱은 성능에 좋지 않은 영향을 미친다.
- 져네릭(generic) 클래스와 메서드를 사용하면 박싱과 언박싱을 피할 수 있다.
- 컴파일러가 자동으로 reference type 변환을 하지 않도록 사용해서 피할 수 있다.
```
int firstNumber = 25;
int secondNumber = 35;
Console.WriteLine($"A few numbers:{firstNumber}, {secondNumber}");
 
// 위 코드의 동작방식
int i = 25;
object o = i; // 박싱
Console.WriteLine(o.ToString());
 
// ToString() 메서드로 박싱을 피할 수 있다
Console.WriteLine($"A few numbers:{firstNumber.ToString()}, {secondNumber.ToString()}");
```
- ***See Also***
    - ***C# 2.0 - generic***


　

### 10. 베이스 클래스가 업그레이드된 경우에만 new 한정자를 사용하라.
---
- 베이스 클래스의 메서드와 하위 클래스에서 재정의한 메서드가 완전히 다른 내용을 구현했다 하더라도 이를 사용하는 대부분의 개발자는 두 메서드가 완전히 동일한 작업을 수행할 것으로 기대한다.
- 베이스 클래스가 업그레이드되어 메서드의 이름이 충돌하는 경우는 매우 특별한 경우라서 new 한정자를 검토해볼 수 있다. 그 외의 경우라면 절대로 new 한정자를 사용하지 말자.

