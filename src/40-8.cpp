// ============================================================================
// 【说明】：演示使用逗号表达式探测类是否拥有指定成员函数（Dump2File）的高级 SFINAE 技巧。
// 【重点】：
//   1. -> decltype(((void)t.Dump2File()), void())
//   2. 对象具备该成员函数时编译通过并调用；没有该成员函数时自动降级到 DumpObj(...) 兜底告警
// ============================================================================
#include <iostream>

class SomeObj1 {
public:
	void Dump2File() const
	{
		std::cout << "dump this object to file" << std::endl;
	}
};

class SomeObj2 {
};

template<class T>
auto DumpObj(const T &t)->decltype(((void)t.Dump2File()), void())
{
	t.Dump2File();
}

void DumpObj(...)
{
	std::cout << "the object must have a member function Dump2File" << std::endl;
}

int main()
{
	DumpObj(SomeObj1());
	DumpObj(SomeObj2());
}
