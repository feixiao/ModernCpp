// ============================================================================
// 【说明】：演示根据成员函数存在性（t.f()）概念自动选择最优类模板偏特化。
// 【重点】：
//   1. 当类型 Arg 拥有 f() 成员函数时，精准命中 template<C T> struct S<T> 偏特化
//   2. 普通类型 int 命中基础通用版本
// ============================================================================
#include <iostream>

template<typename T> concept C = requires (T t) { t.f(); };
template<typename T> struct S {
	S() {
		std::cout << "1.template<typename T> struct S" << std::endl;
	}
};
template<C T> struct S<T> {
	S() {
		std::cout << "2.template<C T> struct S<T>" << std::endl;
	}
};
struct Arg { void f(); };

int main()
{
    S<int> s1;
    S<Arg> s2;
}