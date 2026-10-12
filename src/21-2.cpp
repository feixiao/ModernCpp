// ============================================================================
// 【说明】：演示条件 noexcept 在泛型 swap 函数根据成员是否 noexcept 进行自适应传递。
// 【重点】：
//   1. swap(...) noexcept(noexcept(...)) 结合 std::is_nothrow_move_constructible
//   2. 只有内部移动和赋值都不抛异常时，外部 swap 才承诺 noexcept，提升 STL 容器操作安全性
// ============================================================================
#include <iostream>
#include <type_traits
struct X {
    X() {}
    X(X&&) noexcept {}
    X(const X&) {}
    X operator= (X&&) noexcept { return *this; }
    X operator= (const X&) { return *this; }
};

struct X1 {
    X1() {}
    X1(X1&&) {}
    X1(const X1&) {}
    X1 operator= (X1&&) { return *this; }
    X1 operator= (const X1&) { return *this; }
};

template<typename T>
void swap_impl(T& a, T& b, std::integral_constant<bool, true>) noexcept
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
void swap_impl(T& a, T& b, std::integral_constant<bool, false>)
{
    T tmp(a);
    a = b;
    b = tmp;
}

template<typename T>
void swap(T& a, T& b)
noexcept(noexcept(swap_impl(a, b,
    std::integral_constant<bool, noexcept(T(std::move(a)))
    && noexcept(a.operator=(std::move(b)))>())))
{
    swap_impl(a, b, std::integral_constant<bool, noexcept(T(std::move(a)))
        && noexcept(a.operator=(std::move(b)))>());
}

int main()
{
    X x1, x2;
    swap(x1, x2);

    X1 x3, x4;
    swap(x3, x4);
}
