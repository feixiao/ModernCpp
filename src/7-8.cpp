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
    auto foo = [x, y] { return x * y; };
    Bar bar(x, y);
    std::cout << "foo() = " << foo() << std::endl;
    std::cout << "bar() = " << bar() << std::endl;
}
