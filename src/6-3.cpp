// ============================================================================
// 【说明】：演示 C++11 右值引用（T&&）绑定临时对象并延长生命周期的特性。
// 【重点】：
//   1. X&& x2 = make_x() 使用右值引用接管即将销毁的函数返回值临时对象
//   2. 右值引用延长了临时对象的生存期直至 x2 作用域结束
// ============================================================================
include <iostream>

class X {
public:
	X() { std::cout << "X ctor" << std::endl; }
	X(const X&x) { std::cout << "X copy ctor" << std::endl; }
	~X() { std::cout << "X dtor" << std::endl; }
	void show() { std::cout << "show X" << std::endl; }
};

X make_x()
{
	X x1;
	return x1;
}

int main()
{
	X &&x2 = make_x();
	x2.show();
}
