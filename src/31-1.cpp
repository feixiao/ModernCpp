// ============================================================================
// 【说明】：演示 GCC/Clang 平台扩展对齐属性 __attribute__((aligned(16)))。
// 【重点】：
//   1. C++11 标准化 alignas 之前，编译器依赖平台特有 __attribute__ 语法控制对齐
//   2. 对比展示标准属性与传统扩展语法的写法差异
// ============================================================================
#include <iostream>

#define PRINT_ALIGN(c, v)	\
	std::cout << "alignof(" #c ") = " << alignof(c) \
	<< ", alignof(" #v ") = " << alignof(v) << std::endl

__attribute__((aligned(16))) class X { int i; } a;
class __attribute__((aligned(16))) X1 { int i; } a1;
class X2 { int i; } __attribute__((aligned(16))) a2;
class X3 { int i; } a3 __attribute__((aligned(16)));


int main()
{
	PRINT_ALIGN(X, a);
	PRINT_ALIGN(X1, a1);
	PRINT_ALIGN(X2, a2);
	PRINT_ALIGN(X3, a3);
}
