// ============================================================================
// 【说明】：演示通过类成员模板 get<Idx>() 接入结构化绑定的协议实现形式。
// 【重点】：
//   1. 与 20-10 互补，演示 get 既可以是全局函数，也可以是类自身的成员函数 template<size_t Idx> get()
//   2. 共同构成 C++17 结构化绑定三大解构来源（数组、聚合体、Tuple-like）之一
// ============================================================================
#include <iostream>
#include <tuple>

class BindBase3 {
public:
	int a = 42;
};

class BindTest3 : public BindBase3 {
public:
	double b = 11.7;
	template<std::size_t Idx> auto& get() = delete;

};

template<> auto& BindTest3::get<0>() { return a; }
template<> auto& BindTest3::get<1>() { return b; }

namespace std {
	template<>
	struct tuple_size<BindTest3> {
		static constexpr size_t value = 2;
	};

	template<>
	struct tuple_element<0, BindTest3> {
		using type = int;
	};

	template<>
	struct tuple_element<1, BindTest3> {
		using type = double;
	};
}

int main()
{
	BindTest3 bt3;
	auto& [x3, y3] = bt3;
	x3 = 78;
	std::cout << bt3.a << std::endl;
}
