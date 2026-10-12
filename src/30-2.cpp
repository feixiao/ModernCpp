// ============================================================================
// 【说明】：演示 C++11 alignas 说明符与 alignof 运算符控制与查询自定义内存对齐。
// 【重点】：
//   1. alignas(16) 显式要求结构体或成员按 16 字节边界对齐（满足 SIMD/AVX 指令集要求）
//   2. alignof(type) 查询类型的对齐字节数要求
// ============================================================================
#include <iostream>
struct X
{
	char a1;
	int a2;
	double a3;
};

struct X1
{
	alignas(16) char a1;
	alignas(double) int a2;
	double a3;
};

struct alignas(16) X2
{
	char a1;
	int a2;
	double a3;
};

struct alignas(16) X3
{
	alignas(8) char a1;
	alignas(double) int a2;
	double a3;
};

struct alignas(4) X4
{
	alignas(8) char a1;
	alignas(double) int a2;
	double a3;
};

#define COUT_ALIGN(s) std::cout << "alignof(" #s ") = " << alignof(s) << std::endl
	
int main()
{
	X x;
	X1 x1;
	X2 x2;
	X3 x3;
	X4 x4;
	alignas(4) X3 x5;
	alignas(16) X4 x6;

	COUT_ALIGN(x);
	COUT_ALIGN(x1);
	COUT_ALIGN(x2);
	COUT_ALIGN(x3);
	COUT_ALIGN(x4);
	COUT_ALIGN(x5);
	COUT_ALIGN(x6);

	COUT_ALIGN(x5.a1);	
	COUT_ALIGN(x6.a1);
}
