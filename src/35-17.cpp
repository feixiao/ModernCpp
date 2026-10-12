// ============================================================================
// 【说明】：演示基于二元左折叠表达式将可变参数包连续输出到 std::cout。
// 【重点】：
//   1. (std::cout << ... << args) << std::endl;
//   2. 优雅实现泛型任意长度打印，无需循环或递归
// ============================================================================
#include <iostream>
#include <string>

template<class ...Args>
void print(Args ...args)
{
	(std::cout << ... << args) << std::endl;
}

int main()
{
	print(std::string("hello "), "c++ ", "world");
}
