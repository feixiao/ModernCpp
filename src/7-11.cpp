// ============================================================================
// 【说明】：演示异步场景下 [=] 隐式捕获 this 导致的悬垂引用 Bug，以及 C++17 [*this] 拷贝修复方案。
// 【重点】：
//   1. C++11 中 [=] 捕获成员变量 value 实质上是隐式捕获了 this 指针
//   2. 当 Work tmp 局部对象在 foo() 退出时析构，异步线程访问 value 将访问已销毁内存
//   3. C++14/17 解决方案：通过广义捕获 [tmp = *this] 或 C++17 [*this] 完整拷贝整个对象副本
// ============================================================================
#include <iostream>
#include <future>

class Work
{
  private:
    int value;

  public:
    Work() : value(42) {}
    std::future<int> spawn()
    {
        return std::async([=]() -> int { return value; });
    }
};

/*
class Work
{
  private:
    int value;

  public:
    Work() : value(42) {}
    std::future<int> spawn()
    {
        return std::async([=, tmp = *this]() -> int { return tmp.value; });
    }
};

class Work
{
  private:
    int value;

  public:
    Work() : value(42) {}
    std::future<int> spawn()
    {
        return std::async([=, *this]() -> int { return value; });
    }
};

*/

std::future<int> foo()
{
    Work tmp;
    return tmp.spawn();
}

int main()
{
    std::future<int> f = foo();
    f.wait();
  std::cout << "f.get() = " << f.get() << std::endl;
}
