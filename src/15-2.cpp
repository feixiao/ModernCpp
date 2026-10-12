// ============================================================================
// 【说明】：演示派生类手写非平凡构造函数以实现基类和子类字段初始化的传统写法。
// 【重点】：
//   1. 作为 15-3 聚合继承初始化的对比参考，说明手写构造函数的代码负担
// ============================================================================
#include <iostream>
#include <string>

class MyStringWithIndex : public std::string {
public:
	MyStringWithIndex(const std::string& str, int idx) : std::string(str), index_(idx) {}
	int index_ = 0;
};

std::ostream& operator << (std::ostream &o, const MyStringWithIndex& s)
{
	o << s.index_ << ":" << s.c_str();
	return o;
}

int main()
{
	MyStringWithIndex s("hello world", 11);
	std::cout << s << std::endl;
}
