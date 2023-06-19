### 2.1 namespace
---
- Hello World
    ```
    #include <iostream>
    int main()
    {
        std::cout << "Hello World!" << std::endl;
        system("pause");
        return 0;
    }
    ```
- using namespace xxx
    ```
    #include <iostream>
    using namespace std;
    int main()
    {
        cout << "Hello World!" << endl;
        system("pause");
        return 0;
    }
    ```
- using xxx
    ```
    #include <iostream>
    using std::cout;
    using std::endl;
    int main()
    {
        cout << "Hello World!" << endl;
        system("pause");
        return 0;
    }
    ```
- namespace
    ```
    #include <iostream>

    namespace A
    {
        void y(void)
        {
            std::cout << "A 모듈의 y 함수" << std::endl;
        }
    }

    namespace B
    {
        void y(void)
        {
            std::cout << "B 모듈의 y 함수" << std::endl;
        }
    }

    namespace A
    {
        namespace B
        {
            namespace C
            {
                void y(void)
                {
                    std::cout << "A::B::C 모듈의 y 함수" << std::endl;
                }
            }
        }
    }

    namespace A::B::C::D // C++ 17
    {
        void y(void)
        {
            std::cout << "A::B::C::D 모듈의 y 함수" << std::endl;
        }
    }

    int foo(int x)
    {
        return x;
    }

    int main()
    {
        int result = ::foo(8);
        std::cout << result << std::endl;
        A::y();
        B::y();
        A::B::C::y();
        A::B::C::D::y();

        return 0;
    }
    ```


　

### 2.2 Built-in data type
---
- 기본 데이터 타입과 사용 예
    |데이터 타입|설명|사용 예|
    |:---|:---|:---|
    |int|정수, 표현 가능한 크기는 컴파일러에 따라 다름<br>보통 4바이트|int i = 7;|
    |short (int)|2 바이트 정수|short s = 10;|
    |long (int)|4 바이트 정수|long l = -8;|
    |long long (int)|8 바이트 정수|long long ll = 14;|
    |unsigned int<br>unsigned short (int)<br>unsigned long (int)<br>unsigned long long (int)|부호 없는 정수|unsigned int i = 3;<br>unsigned short s = 32;<br>unsigend long l = 2300;<br>unsigned long long ll = 130;|
    |float|실수(부동소수점 수)|float f = 7.5f;|
    |double|float의 배정도 정밀한 실수|double d = 7.9;|
    |long double|double의 배정도 정밀한 실수|long double ld = 16.98L;|
    |char|8 비트 문자|char c = 'm';|
    |char16_t|16 비트 문자|char16_t c = u'm';|
    |char32_t|32 비트 문자|char32_t c = U'm';|
    |wchar_t|와이드 문자로 컴파일러에 따라 다름|wchar_t w = L'm';|
    |bool|true/false 값을 갖는 논리 타입|bool b = true;|
    |***auto***|***컴파일러에 의해 자동으로 타입이 결정되는 타입***|auto i = 7; // i는 자동으로 int 타입|
    |***decltype(expr)***|***expr에 의해 결정되는 타입을 따르는 타입***|int i = 7;<br>decltype(i) j = 8; // j는 i의 타입을 따르는 int 타입|
- ***See Also***
    - [***C++ 자료형의 크기 및 범위***](https://myblog.opendocs.co.kr/archives/1230)
    - [***부동 소수점(Floating Point)란 무엇인가?***](https://steemit.com/kr/@modolee/floating-point)
    - [***단정도(single precision), 배정도(double precision)이란?***](https://whatisthenext.tistory.com/146)
- auto(C++ 11) 타입은 컴파일러에게 타입추론을 맡긴다는 의미
    ```
    #include <iostream>

    int main()
    {
        auto i = 100;           // i 변수의 타입은 int
        auto j = i;             // j 변수의 타입은 int
        auto d = 106.9L;        // d 변수의 타입은 long double
    }

    auto divide(double a, int b) // 반환 타입은 double
    {
        if (b != 0)
            return a / b;
    }
    ```
- 실제 반환 타입은 -> 뒤에 명시할 수도 있다. (C++ 14)
    ```
    auto foo(int i) -> int
    {
        return i * 2;
    }
    ```
- decltype(expr) 타입은 expr 표현식의 결과로 타입을 결정하라는 의미이고,
- 나중에 설명할 템플릿 함수의 반환 타입을 결정하는데 유용하게 사용된다.
    ```
    int x = 3;
    decltype(x) y = x; // auto y = x;
    auto divide(double a, int b) -> decltype(a / b)
    {
        if (b != 0)
            return a / b;
    }
    ```
- size_t 타입은 32비트 컴퓨터에서는 4바이트로, 64비트 컴퓨터에서는 8바이트로 설정된다.
- 그래서 특정 타입의 메모리 크기를 반환하는 sizeof 함수의 반환 타입으로 사용된다.
- 배열을 사용하는 반복문에서 배열의 인덱스 값의 타입으로도 많이 사용한다.
    ```
    int arr[5] = { 0, 1, 2, 3, 4 };
    for (size_t i = 0; i < 5; ++i)
        std::cout << arr[i] << std::endl;
    ```
- 숫자 표시
    ```
    int a = 10;             // 10진수
    int b = 012;            // 8진수
    int c = 0xA;            // 16진수
    int d = 0b1010;         // 2진수 (C++ 14)
    int e = 100'000'000;    // 숫자 분리자 (C++ 14)
    ```