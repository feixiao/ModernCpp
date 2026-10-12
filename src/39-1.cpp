// ============================================================================
// 【说明】：演示 C++17 用户定义推导指引（User-Defined Deduction Guides）。
// 【重点】：
//   1. MyPair(int, const char*) -> MyPair<long long, std::string>;
//   2. 当以 (5, "hello") 构造时，自定义推导指引覆盖默认推导，精准映射为指定的模板特化
// ============================================================================
template<typename T1, typename T2>
struct MyPair {
	MyPair(T1 x, T2 y)
		: first(x), second(y) {}
	T1 first;
	T2 second;
};

MyPair(int, const char*)->MyPair<long long, std::string>;

MyPair p8(5u, "hello");
MyPair p9(5, "hello");
