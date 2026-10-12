// ============================================================================
// 【说明】：演示 C++11 传统基于递归模板实例化解包求和（引出折叠表达式）。
// 【重点】：
//   1. 递归基：sum(T arg)；递归步：sum(T1 arg1, Args ...args) { return arg1 + sum(args...); }
//   2. 展开会生成多层嵌套调用，编译开销较大
// ============================================================================
#include <iostream>

template<class T>
T sum(T arg)
{
	return arg;
}

template<class T1, class... Args>
auto sum(T1 arg1, Args ...args)
{
	return arg1 + sum(args...);
}

int main()
{
	std::cout << sum(1, 5.0, 11.7) << std::endl;
}
