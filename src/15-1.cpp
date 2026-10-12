// ============================================================================
// 【说明】：演示聚合类（Aggregate Type）概念以及通过 std::is_aggregate_v 进行类型特征检测。
// 【重点】：
//   1. 继承标准类 std::string 的子类默认非聚合（C++17 之前继承类都不是聚合）
//   2. std::is_aggregate_v 用于编译期判断类型是否符合聚合初始化规则
// ============================================================================
#include <iostream>
#include <string>

class MyString : public std::string {};

int main()
{
	std::cout << "std::is_aggregate_v<std::string> = "
		<< std::is_aggregate_v<std::string> << std::endl;
	std::cout << "std::is_aggregate_v<MyString> = "
		<< std::is_aggregate_v<MyString> << std::endl;
}
