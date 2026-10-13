// ============================================================================
// 【说明】：演示 C++17 结构化绑定（Structured Bindings）解包 tuple 的优雅语法。
// 【重点】：
//   1. auto[x, y] = return_multiple_values(); 一行代码完成新变量声明与字段绑定
//   2. x 和 y 自动获得对应字段的类型与值
// ============================================================================
#include <iostream>
#include <tuple>

auto return_multiple_values()
{
	return std::make_tuple(11, 7);
}

int main()
{
	// 使用结构化绑定解包返回的 tuple，x 和 y 自动获得对应字段的类型与值
	auto[x, y] = return_multiple_values();
	std::cout << "x=" << x << " y=" << y << std::endl;
}
