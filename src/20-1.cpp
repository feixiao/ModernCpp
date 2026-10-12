// ============================================================================
// 【说明】：演示传统 C++11 使用 std::tie 解包 std::tuple 多返回值的写法。
// 【重点】：
//   1. 必须预先在外部声明变量 int x = 0, y = 0;
//   2. std::tie(x, y) = return_multiple_values(); 完成解包，代码相对繁琐
// ============================================================================
#include <iostream>
#include <tuple>

std::tuple<int, int> return_multiple_values()
{
	return std::make_tuple(11, 7);
}

int main()
{
	int x = 0, y = 0;
	std::tie(x, y) = return_multiple_values();
	std::cout << "x=" << x << " y=" << y << std::endl;
}
