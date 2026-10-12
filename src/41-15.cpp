// ============================================================================
// 【说明】：演示约束类模板（Constrained Class Template）偏特化优先级高于普通模板。
// 【重点】：
//   1. template<C T> struct X<T> 比通用非约束版本 template<typename T> struct X 更特化
//   2. 编译器优先选择满足 concept 约束的偏特化实例
// ============================================================================
#include <iostream>

template<typename T> concept C = true;
template<typename T> struct X {
	X() { std::cout << "1.template<typename T> struct X" << std::endl; }
};
template<typename T> struct X<T*> {
	X() { std::cout << "2.template<typename T> struct X<T*>" << std::endl; }
};
template<C T> struct X<T> {
	X() { std::cout << "3.template<C T> struct X<T>" << std::endl; }
}; 

int main()
{
    X<int*> s1;
    X<int> s2;
}
