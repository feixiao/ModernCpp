// ============================================================================
// 【说明】：演示统一初始化列表在原生数组与标准库容器（vector/list/set/map）中的一致用法。
// 【重点】：
//   1. C++98 只有原生数组支持聚合初始化 {1, 2, 3}
//   2. C++11 通过 std::initializer_list 扩展到所有 STL 容器，甚至嵌套构造键值对 map
// ============================================================================
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>

int main()
{
	int x[] = { 1,2,3,4,5 };
	int x1[]{ 1,2,3,4,5 };
	// 原生数组的统一初始化列表语法，C++11 支持省略数组大小
	std::vector<int> x2{ 1,2,3,4,5 };
	// vector 的统一初始化列表语法，C++11 支持直接在花括号中列出元素
	std::vector<int> x3 = { 1,2,3,4,5 };
	// list 的统一初始化列表语法，C++11 支持直接在花括号中列出元素
	std::list<int> x4{ 1,2,3,4,5 };
	std::list<int> x5 = { 1,2,3,4,5 };
	// set 的统一初始化列表语法，C++11 支持直接在花括号中列出元素
	std::set<int> x6{ 1,2,3,4,5 };
	std::set<int> x7 = { 1,2,3,4,5 };
	// map 的统一初始化列表语法，C++11 支持直接在花括号中列出键值对
	std::map<std::string, int> x8{ {"bear",4}, {"cassowary",2}, {"tiger",7} };
	std::map<std::string, int> x9 = { {"bear",4}, {"cassowary",2}, {"tiger",7} };
}
