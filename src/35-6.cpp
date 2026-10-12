// ============================================================================
// 【说明】：演示 C++11 传统利用初始化列表与逗号表达式展开形参包执行副作用。
// 【重点】：
//   1. int tmp[] = {(std::cout << args(7, 11) << std::endl, 0) ...};
//   2. 在 C++17 折叠表达式出现前，这是按顺序展开形参包执行函数的标准技巧
// ============================================================================
#include <iostream>

int add(int a, int b) { return a + b; };
int sub(int a, int b) { return a - b; };

template<class ...Args>
void foo(Args (*...args)(int, int))
{
	int tmp[] = {(std::cout << args(7, 11) << std::endl, 0) ...};
}

int main()
{
	foo(add, sub);
}
