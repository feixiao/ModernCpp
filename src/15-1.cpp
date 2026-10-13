// ============================================================================
// 【说明】：演示聚合类（Aggregate Type）概念以及通过 std::is_aggregate_v 进行类型特征检测。
// 【重点】：
//   1. 继承标准类 std::string 的子类默认非聚合（C++17 之前继承类都不是聚合）
//   2. std::is_aggregate_v 用于编译期判断类型是否符合聚合初始化规则
// ============================================================================
#include <iostream>
#include <string>


// 派生类 MyString 继承自 std::string，默认情况下不是聚合类型
// 聚合类是什么？有什么用
// 聚合类是一种特殊的类类型，它满足以下条件：
//   1. 没有用户声明的构造函数（包括默认构造函数）
//   2. 没有私有或受保护的非静态数据成员
//   3. 没有虚函数
//   4. 没有基类
// 聚合类的主要用途是可以使用聚合初始化（aggregate initialization）进行初始化，例如：
//   MyAggregate a{1, 2, 3};
class MyString : public std::string {};

int main()
{
	// 检查 std::string 是否为聚合类型
	// 检查 MyString 是否为聚合类型
	std::cout << "std::is_aggregate_v<std::string> = "
		<< std::is_aggregate_v<std::string> << std::endl;
	std::cout << "std::is_aggregate_v<MyString> = "
		<< std::is_aggregate_v<MyString> << std::endl;
}
