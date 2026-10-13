// ============================================================================
// 【说明】：揭示 Lambda 表达式的本质——编译器自动生成的仿函数（Functor/类对象）。
// 【重点】：
//   1. auto foo = [x, y] { return x * y; } 等价于手写的 class Bar 结构
//   2. 捕获变量对应仿函数的数据成员，函数体对应其重载的 operator()
// ============================================================================
#include <iostream>

class Bar
{
public:
    Bar(int x, int y) : x_(x), y_(y) {}
    // 重载 operator()，实现仿函数的调用操作，返回捕获的 x_ 和 y_ 的乘积
    int operator () ()
    {
        return x_ * y_;
    }
private:
int x_;
int y_;
};

int main()
{
    int x = 5, y = 8;
    // Lambda 表达式按值捕获 x 和 y，生成的闭包对象 foo 内部保存了 x 和 y 的副本
    auto foo = [x, y] { return x * y; };
    Bar bar(x, y);
    std::cout << "foo() = " << foo() << std::endl; // 调用 Lambda 表达式生成的闭包对象 foo 的 operator()
    std::cout << "bar() = " << bar() << std::endl; // 调用手写的仿函数 Bar 的 operator()，效果与 Lambda 相同（按值捕获 x 和 y）
}
