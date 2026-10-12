// ============================================================================
// 【说明】：演示 C++17 超对齐类型（Over-aligned Types）在 new 动态内存分配中的支持。
// 【重点】：
//   1. union alignas(256) X 声明超过标准最大对齐要求的超对齐类型
//   2. C++17 operator new 原生支持超对齐参数重载，自动返回满足 256 字节边界的堆地址
// ============================================================================
#include <iostream>
union alignas(256) X
{
	char a1;
	int a2;
	double a3;
};
int main(int argc, char *argv[])
{
	X *x = new X();
	std::cout << "x = " << x << std::endl;
}
