// ============================================================================
// 【说明】：演示可变参数函数模板与特化/重载函数之间的重载决议优先级。
// 【重点】：
//   1. 具名定参版本（foo(T1 a1, Args... args) 与 foo(T1 a1, T2 a2)）优先于纯可变包版本匹配
// ============================================================================
#include <iostream>

template<class... Args> void foo(Args... args)
{
	std::cout << "foo(Args... args)" << std::endl;
}

template<class T1, class... Args> void foo(T1 a1, Args... args)
{
	std::cout << "foo(T1 a1, Args... args)" << std::endl;
}

template<class T1, class T2> void foo(T1 a1, T2 a2)
{
	std::cout << "foo(T1 a1, T2 a2)" << std::endl;
}

int main()
{
	foo();
	foo(1, 2, 3);
	foo(1, 2);
}
