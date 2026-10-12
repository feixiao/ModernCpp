// ============================================================================
// 【说明】：演示 C++17 多基类继承下的聚合初始化（按基类声明顺序依次初始化）。
// 【重点】：
//   1. 派生类同时继承 string 与 Count
//   2. s{ "hello world", 7, 11 } 依次为各基类和自身派生类成员按声明顺序赋初值
// ============================================================================
#include <iostream>
#include <string>

class Count {
public:
	int Get() { return count_++; }
	int count_ = 0;
};

class MyStringWithIndex : 
	public std::string, 
	public Count {
public:
	int index_ = 0;
};

std::ostream& operator << (std::ostream &o, MyStringWithIndex& s)
{
	o << s.index_ << ":" << s.Get() << ":" << s.c_str();
	return o;
}

int main()
{
	MyStringWithIndex s{ "hello world", 7, 11 };
	std::cout << s << std::endl;
	std::cout << s << std::endl;
}
