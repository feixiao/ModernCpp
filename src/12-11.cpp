// ============================================================================
// 【说明】：演示函数 try 块（Function-try-block）在委托构造函数中的异常捕获。
// 【重点】：
//   1. X() try : X(0) {} catch(int e) {}
//   2. 用于在委托构造发生异常时捕获底层抛出的错误并进行转换处理
// ============================================================================
#include <iostream>

class X
{
public:
	X() try : X(0) {}
	catch (int e)
	{
		std::cout << "catch: " << e << std::endl;
		throw 3;
	}
	X(int a) try : X(a, 0.) {}
	catch (int e)
	{
		std::cout << "catch: " << e << std::endl;
		throw 2;
	}
	X(double b) : X(0, b) {}
	X(int a, double b) : a_(a), b_(b) { throw 1; }
private:
	int a_;
	double b_;
};

int main()
{
	try {
		X x;
	}
	catch (int e) {
		std::cout << "catch: " << e << std::endl;
	}
}
