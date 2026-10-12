// ============================================================================
// 【说明】：演示类成员函数内使用 Lambda 时通过 [this] 捕获当前对象指针。
// 【重点】：
//   1. [this] 捕获当前对象的 this 指针，使 Lambda 内部可直接访问成员函数（print()）和成员变量（x）
//   2. 注意生命周期风险：若异步执行该 Lambda，原对象析构可能导致野指针
// ============================================================================
#include <iostream>

class A
{
public:
    void print()
    {
        std::cout << "class A" << std::endl;
    }

    void test()
    {
        auto foo = [this] { 
            print(); 
            x = 5; 
        };
        foo();
    }
private:
    int x;
};

int main()
{
    A a;
    a.test();
}
