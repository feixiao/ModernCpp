// ============================================================================
// 【说明】：演示默认生成的特殊成员函数（构造、拷贝、移动、析构）的隐式 noexcept 规则。
// 【重点】：
//   1. 编译器自动生成的特殊成员函数，若其所有基类和成员均 noexcept，则默认也是 noexcept
//   2. 使用 noexcept(...) 操作符查询默认构造和拷贝构造函数的异常属性
// ============================================================================
#include <iostream>

struct X {
};

#define PRINT_NOEXCEPT(x)    \
    std::cout << #x << " = " << x << std::endl

int main()
{
    X x;
    std::cout << std::boolalpha;
    PRINT_NOEXCEPT(noexcept(X()));
    PRINT_NOEXCEPT(noexcept(X(x)));
    PRINT_NOEXCEPT(noexcept(X(std::move(x))));
    PRINT_NOEXCEPT(noexcept(x.operator=(x)));
    PRINT_NOEXCEPT(noexcept(x.operator=(std::move(x))));
}
