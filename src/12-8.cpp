// ============================================================================
// 【说明】：演示委托构造函数执行过程中的调用时序与函数体执行先后顺序。
// 【重点】：
//   1. 目标构造函数的初始化列表和函数体先完全执行完毕
//   2. 随后才执行委托构造函数自身函数体中的代码（InitStep1 -> InitStep2 -> InitStep3）
// ============================================================================
#include <iostream>

class X
{
public:
	X() : X(0) { InitStep3(); }
	X(int a) : X(a, 0.) { InitStep2(); }
	X(double b) : X(0, b) {}
	X(int a, double b) : a_(a), b_(b) { InitStep1(); }
private:
	void InitStep1() { std::cout << "InitStep1()" << std::endl; }
	void InitStep2() { std::cout << "InitStep2()" << std::endl; }
	void InitStep3() { std::cout << "InitStep3()" << std::endl; }
	int a_;
	double b_;
};

int main()
{
	X x;
}
