// ============================================================================
// 【说明】：演示 C++11 析构函数默认隐式声明为 noexcept(true) 的关键机制。
// 【重点】：
//   1. 类的析构函数默认自动是 noexcept 的（除非有成员显式标注 noexcept(false)）
//   2. 析构函数若抛出异常将直接导致 std::terminate，阻止双重异常导致崩溃
// ============================================================================
#include <iostream>

struct M {
    ~M() noexcept(false) {}
};

struct X {
};

struct X1 {
    ~X1() {}
};

struct X2 {
    ~X2() noexcept(false) {}
};

struct X3 {
    M m;
};

#define PRINT_NOEXCEPT(x)    \
    std::cout << #x << " = " << x << std::endl

int main()
{
    X *x = new X;
    X1 *x1 = new X1;
    X2 *x2 = new X2;
    X3 *x3 = new X3;
    std::cout << std::boolalpha;
    PRINT_NOEXCEPT(noexcept(x->~X()));
    PRINT_NOEXCEPT(noexcept(x1->~X1()));
    PRINT_NOEXCEPT(noexcept(x2->~X2()));
    PRINT_NOEXCEPT(noexcept(x3->~X3()));
    PRINT_NOEXCEPT(noexcept(delete x));
    PRINT_NOEXCEPT(noexcept(delete x1));
    PRINT_NOEXCEPT(noexcept(delete x2));
    PRINT_NOEXCEPT(noexcept(delete x3));
}
