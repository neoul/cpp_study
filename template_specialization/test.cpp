#include <iostream>

class Case1 {
public:
    template <typename T>
    void MyMethod(T value) {
        std::cout << "Generic Method: " << value << std::endl;
    }

    // // 클래스 내에서 템플릿 특수화 구현
    // // MSVC (MS virual Studio)에서는 템플릿 특수화 구현이 클래스 내부에 있어도 동작
    // template <>
    // void MyMethod(int value) {
    //     std::cout << "Specialized Method for int: " << value << std::endl;
    // }
};

// 표준에서는 템플릿 특수화 구현이 클래스 외부에 있어야 함
template <>
void Case1::MyMethod(int value) {
    std::cout << "Specialized Method for int: " << value << std::endl;
}

class Case2 {
public:
    template <int T>
    void MyMethod() {
        std::cout << "Generic Method: " << T << std::endl;
    }

    // // 클래스 내에서 템플릿 특수화 구현
    // // MSVC (MS virual Studio)에서는 템플릿 특수화 구현이 클래스 내부에 있어도 동작
    // template <>
    // void MyMethod(int value) {
    //     std::cout << "Specialized Method for int: " << value << std::endl;
    // }
};

// 표준에서는 템플릿 특수화 구현이 클래스 외부에 있어야 함
template <>
void Case2::MyMethod<42>() {
    std::cout << "Specialized Method for 42!!! " << 42 << std::endl;
}

int main() {
    Case1 case1;
    case1.MyMethod<double>(3.14);  // 일반 메소드 호출
    case1.MyMethod<int>(42);    // int에 대한 특수화된 메소드 호출

    Case2 case2;
    case2.MyMethod<1>();  // 일반 메소드 호출
    case2.MyMethod<42>();    // int에 대한 특수화된 메소드 호출
    return 0;
}
