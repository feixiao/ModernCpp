// ============================================================================
// 【说明】：深入探究结构化绑定的底层工作机制：隐藏对象副本与别名映射。
// 【重点】：
//   1. auto[x, y] = bt; 会生成隐藏的完整副本对象，x 与 y 本质是该副本成员的引用别名
//   2. 打印地址证实 &x 与原对象 &bt.a 地址不同（绑定的是副本），auto& 时才指向原对象
// ============================================================================
#include <iostream>
#include <string>

struct BindTest {
	int a = 42;
	std::string b = "hello structured binding";
};

int main()
{
	BindTest bt;
	const auto[x, y] = bt;

	std::cout << "&bt.a=" << &bt.a << " &x=" << &x << std::endl;
	std::cout << "&bt.b=" << &bt.b << " &y=" << &y << std::endl;
	std::cout << "std::is_same_v<const int, decltype(x)>=" 
		<< std::is_same_v<const int, decltype(x)> << std::endl;
	std::cout << "std::is_same_v<const std::string, decltype(y)>=" 
		<< std::is_same_v<const std::string, decltype(y)> << std::endl;
}

/*

int main()
{
	BindTest bt;
	auto&[x, y] = bt;

	std::cout << "&bt.a=" << &bt.a << " &x=" << &x << std::endl;
	std::cout << "&bt.b=" << &bt.b << " &y=" << &y << std::endl;
	
	x = 11;
	std::cout << "bt.a=" << bt.a << std::endl;
	bt.b = "hi structured binding";
	std::cout << "y=" << y << std::endl;
}

*/