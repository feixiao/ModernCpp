// ============================================================================
// 【说明】：演示 C++17 CTAD 彻底淘汰 make_xxx 辅助函数，直接构造类模板包装器。
// 【重点】：
//   1. LambdaWarp x([](int a, int b) { ... });
//   2. 构造函数直接自动捕获未命名的 Lambda 闭包类型 T，大幅简化泛型代码
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
	LambdaWarp x([](int a, int b) {
		std::cout << a + b << std::endl;
	});
	x(11, 7);
}
