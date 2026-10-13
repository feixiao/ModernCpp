// ============================================================================
// 【说明】：演示 C++11 基于范围的 for 循环（Range-based for loop）遍历数组与 STL 容器。
// 【重点】：
//   1. for (const auto &e : index_map) 清晰遍历 std::map 键值对元素
//   2. 自动由编译器展开为迭代器 begin() / end() 的循环控制
// ============================================================================
#include <iostream>
#include <string>
#include <map>

std::map<int, std::string> index_map{ {1, "hello"}, {2, "world"}, {3, "!"} };
int int_array[] = { 0, 1, 2, 3, 4, 5 };

int main()
{
	// 遍历 std::map 的键值对元素
	for (const auto &e : index_map) {
		// e.first 是键，e.second 是值
		std::cout << "key=" << e.first << ", value=" << e.second << std::endl;
	}
	// 遍历数组 int_array 的元素
	for (auto e : int_array) {
		std::cout << e << std::endl;
	}
}
