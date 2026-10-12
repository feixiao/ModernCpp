// ============================================================================
// 【说明】：演示 C++11 允许在模板嵌套尖括号中使用连续两个右尖括号 >> 而不被误判为右移运算符。
// 【重点】：
//   1. C++03 中 Y<X<1> > 必须在两尖括号间手写空格，否则会被当成 operator>> 报语法错误
//   2. C++11 修复词法分析规则，Y<X<1>> 能够正确识别为双层嵌套模板闭合
// ============================================================================
#include <iostream>

template<int I> struct X {
	static int const c = 2;
};
template<> struct X<0> {
	typedef int c;
};
template<typename T> struct Y {
	static int const c = 3;
};
static int const c = 4;
int main() {
	std::cout << (Y<X<1> >::c > ::c > ::c) << std::endl;
	std::cout << (Y<X< 1>>::c > ::c > ::c) << std::endl;
}
