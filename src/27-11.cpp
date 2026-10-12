// ============================================================================
// 【说明】：演示利用 C++17 if constexpr 消除模板全特化、在单一函数内合并逻辑。
// 【重点】：
//   1. if constexpr (std::is_same<T, double>::value)
//   2. 不满足条件的分支会在编译期被丢弃，不参与该类型实例的代码生成
// ============================================================================
#include <type_traits>
template<class T> bool is_same_value(T a, T b)
{
	if constexpr (std::is_same<T, double>::value) {
		if (std::abs(a - b) < 0.0001) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return a == b;
	}
}
