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

- ***auto(C++ 11)*** 타입은 컴파일러에게 타입추론을 맡긴다는 의미
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
- ***decltype(expr)*** 타입은 ***expr*** 표현식의 결과로 타입을 결정하라는 의미이고,
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
- ***size_t*** 타입은 32비트 컴퓨터에서는 4바이트로, 64비트 컴퓨터에서는 8바이트로 설정된다.
- 그래서 특정 타입의 메모리 크기를 반환하는 ***sizeof*** 함수의 반환 타입으로 사용된다.
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
- ***See Also***
    - [***C++ 자료형의 크기 및 범위***](https://myblog.opendocs.co.kr/archives/1230)
    - [***부동 소수점(Floating Point)란 무엇인가?***](https://steemit.com/kr/@modolee/floating-point)
    - [***단정도(single precision), 배정도(double precision)이란?***](https://whatisthenext.tistory.com/146)


　

### 2.3 inline functions
---
- inline 함수는 C의 매크로 함수를 대체하는 기능을 제공한다.
    ```
    #include <iostream>
    using namespace std;

    // C 매크로 함수
    //#define SQ(x) (x) * (x)

    // C++ 인라인 함수
    inline int SQ(int x)
    {
        return x * x;
    }

    int main()
    {
        cout << SQ(8) << '\n';
        cout << SQ(9 + 5) << '\n';
    }
    ```


　

### 2.4 const keyword
---
- const 키워드를 포인터와 함께 사용할 때는 주의가 필요하다.
- 가리키는 데이터를 상수화하는 포인터를 ***"상수 포인터라고"*** 부른다.
    ```
    double e = 2.71828;
    const double* doublePtr = &e; // 또는 double const* doublePtr = &e;
    *doublePtr = 20.3027; // C3892 - 컴파일 오류
    ```
- 반면, 포인터 자체가 상수화된 포인터를 ***"포인터 상수라고"*** 부른다.
    ```
    double e = 2.71828;
    double r = 3.894;
    double* const doublePtr = &e;
    *doublePtr = 20.3027;
    doublePtr = &r; // C3892 - 컴파일 오류
    ```


　

### 2.5 enum & struct
---
- 열거형 값을 일반 정수와 비교할 수 없게 만드는 ***엄격한 열거형 타입(strongly typed enumeration type)이*** C++ 11에 도입되었다.
    ```
    #include <iostream>

    enum class Suit { clubs, diamonds, hearts, spades };

    struct Card
    {
        Suit s;
        int rank;
    };
    Card deck[52];

    int main()
    {
        if (deck[3].s == 0) // C2676 - 컴파일 에러
            std::cout << "clubs" << std::endl;

        if (deck[3].s == Suit::clubs)
            std::cout << "clubs" << std::endl;
    }
    ```


　

### 2.7 references
---
- 변수 선언이란 메모리 공간에 이름을 붙이는 것을 말한다.
- ***참조자(reference)는*** 이 메모리 공간에 별명으로 이름을 하나 더 붙이는 것을 말한다.
    ```
    int n = 10;
    int& nn = n;
    ```
- 숫자나 표현식의 결과처럼 이름 없는 값에는 별명을 붙일 수 없으므로 레퍼런스를 정의할 수 없다.
    ```
    int& k = 7;
    int a = 2, b = 3;
    int& j = a + b;
    ```
- 숫자와 같이 이름이 없는 값을 ***임시값이라고*** 부른다.
- 임시값은 메모리의 ***상수영역에*** 이름이 붙지 않는 임시 공간이 생성되고 값이 저장되어 사용된다.
- 상수 레퍼런스로 정의하면 임시값으로도 초기화할 수 있지만 값을 변경할 수는 없다.
    ```
    const int& k = 5;
    ```
- 기존 변수로 한번 초기화한 레퍼런스는 그 대상을 변경할 수 없다.
    ```
    int x = 3, y = 4;
    int& r = x;
    r = y; // 변수 x의 값이 4로 변경, r의 대상이 y로 변경되는 것은 아님
    ```


　

### 2.7.1 call by reference
---
- C++은 레퍼런스 전달 호출(call by reference)을 지원한다.
    ```
    #include <iostream>
    using namespace std;

    void squareCube(int& s, int& c)
    {
        s = s * s;
        c = c * c * c;
    }

    int main()
    {
        int number, square, cube;
        cout << "정수 입력: ";
        cin >> number;
        square = cube = number;
        squareCube(square, cube);
        cout << number << "의 제곱은 " << square << endl;
        cout << "세제곱은 " << cube << "입니다" << endl;
        return 0;
    }
    /*출력결과
    정수 입력: 5
    5의 제곱은 25
    세제곱은 125입니다
    */
    ```
- 함수가 파라미터로 받은 값을 변경하지 않게 하려면 ***상수 레퍼런스 전달(call-by-constant reference)*** 방식을 사용할 수 있다.
    ```
    void squareCube(const int& s, const int& c)
    {
        ...
    }
    ```


　

### 2.7.2 return by reference
---
- 닥치고 예제
    ```
    #include <iostream>

    int& max(int& a, int& b)
    {
        return (a > b) ? a : b;
    }

    int main()
    {
        int i = 20, j = 10;
        int& k = max(i, j);
        std::cout << k << std::endl;
        i = 3;
        std::cout << k << std::endl;
        return 0;
    }
    /* 출력결과
    20
    3
    */
    ```


　

### 2.8 r-value reference (C++ 11)
---
    int x = 2, y = 3;   // 상수인 2와 3을 x와 y에 배정
    int z = x + y;      // x + y 표현식의 결과인 5를 z에 배정
- 좌측값(l-value)
    > - x, y, z
    > - 메모리 공간이 생성되고 이 공간에 이름이 주어지는 대상을 의미
    > - &x나 &y와 같이 & 연산자로 주소값을 얻을 수 있다.
    > - 배정 연산자의 좌측이나 우측에 올 수 있다.
- 우측값(r-value)
    > - 2, 3, x + y
    > - 배정 연산의 우측에 놓이게 되는 상수나 표현식의 결과인 ***임시값***
    > - 메모리의 상수 영역에 임시로 생성되어 사용.
    > - 사용 후에는 바로 버려질 대상들이다.
    > - 배정 연산자의 우측에만 올 수 있다.
- 좌측값 레퍼런스(l-value reference)
    > - l-value에 대한 reference
- 우측값 레퍼런스(r-value reference)
    > - r-value에 대한 reference
    > - 메모리의 상수 영역이 아닌 곳에 메모리 공간을 생성하고, 생성된 공간에 이름을 붙여 줘서 일반 변수화하는 것.
    > - 동작성으로만 보면 걍 일반 변수와 같다.
    ```
    int x = 2, y = 3;
    int&& m = 3;            // int m = 3; 과 같은 효과
    int&& k = x + y;        // int k = x + y; 와 같은 효과
    int&& t = std::move(x); // t는 x의 별명이 아니고 int t = x;와 같은 효과
    ```
- 그런데 굳이 왜 필요한 것인가?
    ```
    #include <iostream>

    void increment(int& value)
    {
        std::cout << "좌측값 레퍼런스로 증가" << std::endl;
        ++value;
    }

    void increment(int&& value)
    {
        std::cout << "우측값 레퍼런스로 증가" << std::endl;
        ++value;
    }

    int main()
    {
        int a = 10, b = 20;
        increment(a);
        std::cout << a << std::endl;
        increment(a + b);
        increment(3);
        return 0;
    }
    /* 출력결과
    좌측값 레퍼런스로 증가
    11
    우측값 레퍼런스로 증가
    우측값 레퍼런스로 증가
    */
    ```
- l-value reference 함수만 사용
    ```
    #include <iostream>

    void increment(const int& value)
    {
        std::cout << "좌측값 레퍼런스로 증가" << std::endl;
        // ++value; 에러, value를 수정할 수 없다.
    }

    int main()
    {
        int a = 10, b = 20;
        increment(a);
        std::cout << a << std::endl;
        increment(a + b);
        increment(3);
        return 0;
    }
    /* 출력결과
    좌측값 레퍼런스로 증가
    10
    좌측값 레퍼런스로 증가
    좌측값 레퍼런스로 증가
    */
    ```
- r-value reference 함수만 사용
    ```
    #include <iostream>

    void increment(int&& value)
    {
        std::cout << "우측값 레퍼런스로 증가" << std::endl;
        ++value;
    }

    int main()
    {
        int a = 10, b = 20;
        // increment(a); 에러, l-value reference에 맞는 함수가 없다.
        increment(std::move(a)); // l-value를 r-value로 변환
        std::cout << a << std::endl; // a는 더이상 의미 있는 값이 아니므로 새로운 값을 배정하거나 사용하지 않도록 한다.
        increment(a + b);
        increment(3);
        return 0;
    }
    /* 출력결과
    우측값 레퍼런스로 증가
    11
    우측값 레퍼런스로 증가
    우측값 레퍼런스로 증가
    */
    ```
- 이러한 구분을 위해서 우측값 레퍼런스의 사용은 필수이다.
- 그렇다면, 우측값 전달과 좌측값 전달을 왜 구분해야 할까?
- 이에 대한 답은 ***이동 시맨틱(move semantic C++ 11)에서*** 설명한다.


　

### 2.10 string type
---
- string type 활용 예
    ```
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        string str1 = "hello ";
        string str2("world");
        const char* cstr = str2.c_str();
        cout << "C string is " << cstr << endl;

        string str3 = str1 + str2;
        cout << "combined string is " << str3 << endl;

        if (str3 == "hello world")
            cout << "two strings are same" << endl;

        string myString = "hi";
        myString += ", there";
        string myOtherString = myString;
        if (myString == myOtherString)
            myOtherString[0] = 'H';
        cout << "value of myString is " << myString << endl;
        cout << "value of myOtherString is " << myOtherString << endl;

        long double d = 3.14;
        string s1 = to_string(d);
        cout << "double number is " << d << endl;
        cout << "string version is " << s1 << endl;

        const string s2 = "1234";
        int i = stoi(s2);
        cout << "string is " << s2 << endl;
        cout << "integer version is " << i << endl;

        return 0;
    }
    /* 출력결과
    C string is world
    combined string is hello world
    two strings are same
    value of myString is hi, there
    value of myOtherString is Hi, there
    double number is 3.14
    string version is 3.140000
    string is 1234
    integer version is 1234
    */
    ```


　

### 2.12 Mathematical constant (C++ 20)
---
- 수학에서 사용하는 다양한 상수를 제공한다.
    ```
    #include <iostream>
    #include <numbers>

    int main()
    {
        std::cout << "Pi: " << std::numbers::pi << std::endl;
        std::cout << "e: " << std::numbers::e << std::endl;
        std::cout << "log2(e): " << std::numbers::log2e << std::endl;
        std::cout << "log10(e): " << std::numbers::log10e << std::endl;
        std::cout << "ln(2): " << std::numbers::ln2 << std::endl;
        std::cout << "ln(10): " << std::numbers::ln10 << std::endl;
        std::cout << "sqrt(2): " << std::numbers::sqrt2 << std::endl;
        std::cout << "sqrt(3): " << std::numbers::sqrt3 << std::endl;
        return 0;
    }
    /* 출력결과
    Pi: 3.14159
    e: 2.71828
    log2(e): 1.4427
    log10(e): 0.434294
    ln(2): 0.693147
    ln(10): 2.30259
    sqrt(2): 1.41421
    sqrt(3): 1.73205
    */
    ```