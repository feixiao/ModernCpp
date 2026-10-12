// ============================================================================
// 【说明】：演示 C++11 noexcept 说明符与 noexcept 运算符的基本语法。
// 【重点】：
//   1. foo() noexcept 声明函数绝不抛出异常；foo2() throw() 是已被废弃的旧式规范
//   2. noexcept(expr) 运算符在编译期查询表达式是否保证不抛出异常（返回 bool）
// ============================================================================
#include <iostream>
int foo() noexcept
{
    return 42;
}

int foo1()
{
    return 42;
}

int foo2() throw()
{
    return 42;
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "noexcept(foo())  = " << noexcept(foo()) << std::endl;
    std::cout << "noexcept(foo1()) = " << noexcept(foo1()) << std::endl;
    std::cout << "noexcept(foo2()) = " << noexcept(foo2()) << std::endl;
}
