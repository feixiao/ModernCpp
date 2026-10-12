// ============================================================================
// 【说明】：演示 C++17 放宽聚合体定义：允许派生类从基类公有继承并使用聚合列表初始化。
// 【重点】：
//   1. MyStringWithIndex 公有继承 string 且无手写构造函数
//   2. C++17 允许使用嵌套大括号直接初始化：MyStringWithIndex s{ {"hello world"}, 11 };
// ============================================================================
#include <iostream>
#include <string>

class MyStringWithIndex : public std::string {
public:
	int index_ = 0;
};

std::ostream& operator << (std::ostream &o, const MyStringWithIndex& s)
{
	o << s.index_ << ":" << s.c_str();
	return o;
}

int main()
{
	MyStringWithIndex s{ {"hello world"}, 11 };
	std::cout << s << std::endl;
}
