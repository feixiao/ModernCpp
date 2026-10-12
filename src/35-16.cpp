// ============================================================================
// 【说明】：演示折叠表达式展开顺序对不可逆运算符（如 std::string 与 const char* 相加）的影响。
// 【重点】：
//   1. "c++ " + "world" 会先触发两原生指针相加引发编译错误
//   2. 说明使用折叠表达式时需要关注左折叠与右折叠的结合律
// ============================================================================
#include <iostream>
#include <string>

template<class... Args>
auto sum(Args ...args)
{
	return (args + ...);
}

int main()
{
	std::cout << sum(std::string("hello "), "c++ ", "world") << std::endl;	// 编译错误
}
