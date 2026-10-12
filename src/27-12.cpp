// ============================================================================
// 【说明】：演示 if constexpr 丢弃分支允许不同分支拥有不同返回类型的特性。
// 【重点】：
//   1. double 分支返回 double 类型，else 分支返回 int 类型
//   2. 编译器根据丢弃分支只实例化匹配的 return 语句，顺利完成统一返回类型推导
// ============================================================================
#include <iostream>
#include <type_traits>
template<class T> auto minus(T a, T b)
{
	if constexpr (std::is_same<T, double>::value) {
		if (std::abs(a - b) < 0.0001) {
			return 0.;
		}
		else {
			return a - b;
		}
	}
	else {
		return static_cast<int>(a - b);
	}
}

int main()
{
	std::cout << minus(5.6, 5.11) << std::endl;
	std::cout << minus(5.60002, 5.600011) << std::endl;
	std::cout << minus(6, 5) << std::endl;
}
