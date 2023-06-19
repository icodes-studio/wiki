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
- Using namespace xxx
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


　

### Built-in data type
---
- 기본 데이터 타입과 사용 예