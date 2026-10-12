// ============================================================================
// 【说明】：演示聚合成员的异常规格如何决定外层类编译器合成函数的 noexcept 属性。
// 【重点】：
//   1. 类 X 包含成员 M m
//   2. M 显式声明了部分 noexcept 成员，类 X 的移动构造与赋值会自动继承该安全属性
// ============================================================================
#include <iostream>

struct M {
    M() {}
    M(const M&) {}
    M(M&&) noexcept {}
    M operator= (const M&) noexcept { return *this; }
    M operator= (M&&) { return *this; }
};

struct X {
    M m;
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
