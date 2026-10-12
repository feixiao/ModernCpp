// ============================================================================
// 【说明】：演示基于范围的 for 循环结合结构化绑定高效遍历结构体容器。
// 【重点】：
//   1. for (const auto& [x, y] : bt)
//   2. 每次迭代直接引用每个对象的内部属性，大幅提升代码可读性
// ============================================================================
#include <iostream>
#include <string>
#include <vector>

struct BindTest {
	int a = 42;
	std::string b = "hello structured binding";
};

int main()
{
	std::vector<BindTest> bt{ {11, "hello"},  {7, "c++"},  {42, "world"} };
	for (const auto& [x, y] : bt) {
		std::cout << "x=" << x << " y=" << y << std::endl;
	}
}
