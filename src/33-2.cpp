// ============================================================================
// 【说明】：演示利用 co_yield 配合生成器（generator）实现惰性值序列生成。
// 【重点】：
//   1. 循环体内调用 co_yield i 挂起当前协程并向外输出数据
//   2. 外部可通过基于范围的 for 循环每次按需拉取下一个数据，内存消耗极低
// ============================================================================
#include <iostream>
#include <experimental/generator>

std::experimental::generator<int> foo()
{
	std::cout << "begin" << std::endl;
	for (int i = 0; i < 10; i++) {
		co_yield i;
	}
	std::cout << "end" << std::endl;
}

int main()
{
	for (auto i : foo()) {
		std::cout << i << std::endl;
	}
}
