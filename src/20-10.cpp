// ============================================================================
// 【说明】：演示为自定义类扩展 std::tuple_size、tuple_element 与非成员 get 函数以接入结构化绑定（类 tuple 协议）。
// 【重点】：
//   1. 特化 std::tuple_size<BindTest3> 与 std::tuple_element<Idx, BindTest3>
//   2. 提供全局 template<size_t Idx> auto& get(BindTest3&)
//   3. 允许私有成员或跨层继承的复杂类通过定制协议实现结构化绑定
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
};

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


template<std::size_t Idx>
auto& get(BindTest3 &bt) = delete;

template<>
auto& get<0>(BindTest3 &bt) { return bt.a; }

template<>
auto& get<1>(BindTest3 &bt) { return bt.b;}

int main()
{
	BindTest3 bt3;
	auto& [x3, y3] = bt3;
	x3 = 78;
	std::cout << bt3.a << std::endl;
}
