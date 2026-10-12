// ============================================================================
// 【说明】：演示 C++17 之前为了针对浮点数做容差比较而必须手写模板全特化的繁琐方式。
// 【重点】：
//   1. 必须单独编写 template<> bool is_same_value<double> 特化分支
//   2. 作为 27-11 中 if constexpr 优化方案的对比代码
// ============================================================================
#include <iostream>

template<class T> bool is_same_value(T a, T b)
{
	return a == b;
}

template<> bool is_same_value<double>(double a, double b)
{
	if (std::abs(a - b) < 0.0001) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	double x = 0.1 + 0.1 + 0.1 - 0.3;
	std::cout << std::boolalpha;
	std::cout << "is_same_value(5, 5)	: " << is_same_value(5, 5) << std::endl;
	std::cout << "x == 0.0			: " << (x == 0.) << std::endl;
	std::cout << "is_same_value(x, 0.)	: " << is_same_value(x, 0.) << std::endl;
}
