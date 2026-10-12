// ============================================================================
// 【说明】：演示 C++ 结构体数据成员默认字节对齐规则与内存空洞（Padding）。
// 【重点】：
//   1. struct A 中 char a1; int a2; double a3 产生内部内存填充
//   2. 结构体总大小大于各成员 sizeof 之和，展示对齐对内存开销的影响
// ============================================================================
#include <iostream>

struct A
{
	char a1;
	int a2;
	double a3;
};

struct B
{
	short b1;
	bool b2;
	double b3;
};

int main()
{
	std::cout << "sizeof(A::a1) + sizeof(A::a2) + sizeof(A::a3) = " 
		<< sizeof(A::a1) + sizeof(A::a2) + sizeof(A::a3) << std::endl;
	std::cout << "sizeof(B::b1) + sizeof(B::b2) + sizeof(B::b3) = " 
		<< sizeof(B::b1) + sizeof(B::b2) + sizeof(B::b3) << std::endl;
	std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
	std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
}
