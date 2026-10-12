// ============================================================================
// 【说明】：演示 C++17 decltype(auto) 作为非类型模板参数时的精确类型推导规则。
// 【重点】：
//   1. template<decltype(auto) N> 会精确保留传入实参的值类别与引用属性
//   2. f<x>()：实参为标识符 x，推导为 const int
//   3. f<(x)>()：实参为带括号表达式 (x)，是左值表达式，精确推导为 const int&
// ============================================================================
#include <iostream>
template<decltype(auto) N>
void f()
{
	std::cout << N << std::endl;
}

static const int x = 11;
static int y = 7;

int main()
{
	f<x>();		// N为const int类型
	f<(x)>();	// N为const int&类型
    // f<y>();		// 编译错误
	f<(y)>();	// N为int&类型
}
