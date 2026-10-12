// ============================================================================
// 【说明】：演示通过 constexpr 泛型函数返回值模拟常量常量的写法。
// 【重点】：
//   1. template<class T> constexpr T PI() { return ...; }
//   2. 调用时必须多带括号 PI<int>()，写法不够自然
// ============================================================================
#include <iostream>

template<class T>
constexpr T PI()
{
	return static_cast<T>(3.1415926535897932385);
}

int main()
{
	std::cout << PI<int>() << std::endl;
}
