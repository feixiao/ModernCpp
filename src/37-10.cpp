// ============================================================================
// 【说明】：演示 C++20 结构化字面量类作为非类型模板实参（编译期字符串字面量模板）。
// 【重点】：
//   1. basic_fixed_string 拥有 constexpr 构造函数，支持字面量类（Literal Class）规则
//   2. template <basic_fixed_string Str> struct X 实现原生编译期定长字符串模板参数
// ============================================================================
template <typename T, std::size_t N>
struct basic_fixed_string
{
	constexpr basic_fixed_string(const T(&foo)[N + 1])
	{
		std::copy_n(foo, N + 1, data_);
	}
	
	T data_[N + 1];
};
template <typename T, std::size_t N>
basic_fixed_string(const T(&str)[N])->basic_fixed_string<T, N - 1>;

template <basic_fixed_string Str>
struct X {
	X() {
		std::cout << Str.data_;
	}
};

X<"hello world"> x;
