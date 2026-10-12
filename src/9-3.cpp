// ============================================================================
// 【说明】：演示自定义类如何通过接收 std::initializer_list 构造函数支持初始化列表。
// 【重点】：
//   1. 自定义构造函数接收 std::initializer_list<std::string>
//   2. 通过 begin() / end() 迭代器遍历外部传入的任意长度元素列表
// ============================================================================
#include <iostream>
#include <string>

struct C {
	C(std::initializer_list<std::string> a)
	{
		for (const std::string* item = a.begin(); item != a.end(); ++item) {
			std::cout << *item << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	C c{ "hello", "c++", "world" };
}
