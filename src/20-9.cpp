// ============================================================================
// 【说明】：演示结构化绑定遍历 std::map 时替代传统 pair.first / pair.second。
// 【重点】：
//   1. 传统迭代 map 必须使用 elem.first 与 elem.second，语义抽象
//   2. C++17 可写为 for (const auto& [id, str] : id2str)，代码直观易懂
// ============================================================================
#include <iostream>
#include <string>
#include <map>

int main()
{
	std::map<int, std::string> id2str{ {1, "hello"}, 
	{3, "Structured"}, {5, "bindings"} };

	for (const auto& elem : id2str) {
		std::cout << "id=" << elem.first
			<< ", str=" << elem.second << std::endl;
	}
}
