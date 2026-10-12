// ============================================================================
// 【说明】：演示 requires 表达式中的类型要求（Type Requirement: typename T::xxx）。
// 【重点】：
//   1. typename T::inner（要求存在嵌套类型）
//   2. typename S<T>（要求类模板能够特化）
//   3. typename Ref<T>（要求别名模板能够特化）
// ============================================================================
template<typename T, typename T::type = 0> struct S;
template<typename T> using Ref = T&;
template<typename T> concept C = requires {
	typename T::inner; 	// 要求嵌套类型
	typename S<T>;		// 要求类模板特化
	typename Ref<T>; 		// 要求别名模板特化
};

template <C c>
struct M {};

struct H {
	using type = int;
	using inner = double;
};

M<H> m;
