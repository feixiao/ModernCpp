// ============================================================================
// 【说明】：演示 C++17 之前为了封装通用闭包仿函数而必须依靠辅助工厂函数（make_xxx）的模式。
// 【重点】：
//   1. 传统因为类模板无法推导必须手写类似 std::make_pair 的工厂函数
//   2. 作为 38-6 CTAD 简化方案的对比
// ============================================================================
#include <iostream>

template<class T>
struct LambdaWarp
{
	LambdaWarp(T t) : func(t) {}
	template<class ... Args>
	void operator() (Args&& ... arg)
	{
		func(std::forward<Args>(arg)...);
	}
	T func;
};

int main()
{
	auto l = [](int a, int b) { 
		std::cout << a + b << std::endl; 
	};

	LambdaWarp<decltype(l)> x(l);
	x(11, 7);
}
