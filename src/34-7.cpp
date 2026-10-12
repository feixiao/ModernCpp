// ============================================================================
// 【说明】：演示 C++17 强制复制消除（Guaranteed Copy Elision）在纯右值返回时的绝对保证。
// 【重点】：
//   1. 类 X 的拷贝构造函数被私有化甚至删除（不可拷贝）
//   2. return X(); 返回纯右值在 C++17 中属于严格的强制复制消除，即使拷贝构造不存在也能成功编译
// ============================================================================
#include <iostream>
class X {
public:
	X() { std::cout << "X ctor" << std::endl; }
	~X() { std::cout << "X dtor" << std::endl; }
private:
	X(const X&x) { std::cout << "X copy ctor" << std::endl; }
};

X make_x()
{
	return X();
}

int main()
{
	X x2 = make_x();
}
