// ============================================================================
// 【说明】：演示多个不同分支返回不同局部变量时 NRVO 无法施展的局限性。
// 【重点】：
//   1. 根据条件分别返回 x1 或 x2 导致编译器无法在进入前确定复用哪个对象的内存
//   2. 导致无法执行 NRVO，必须回退到移动构造或拷贝构造
// ============================================================================
#include <iostream>
#include <ctime>

class X {
public:
	X() { std::cout << "X ctor" << std::endl; }
	X(const X&x) { std::cout << "X copy ctor" << std::endl; }
	~X() { std::cout << "X dtor" << std::endl; }
};

X make_x()
{
	X x1, x2;
	if (std::time(nullptr) % 50 == 0) {
		return x1;
	}
	else {
		return x2;
	}
}

int main()
{
	X x3 = make_x();
}
