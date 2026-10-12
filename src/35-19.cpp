// ============================================================================
// 【说明】：演示 C++17 允许在 using 声明中使用形参包展开（Pack Expansion in using）。
// 【重点】：
//   1. using base<Args>::base...;
//   2. 一行代码继承所有模板基类的同名构造函数或成员方法
// ============================================================================
#include <iostream>
#include <string>

template<class T>
class base {
public:
	base() {}
	base(T t) : t_(t) {}
private:
	T t_;
};

template<class... Args>
class derived : public base<Args>...
{
public:
	using base<Args>::base...;
};

int main()
{
	derived<int, std::string, bool> d1 = 11;
	derived<int, std::string, bool> d2 = std::string("hello");
	derived<int, std::string, bool> d3 = true;
}
