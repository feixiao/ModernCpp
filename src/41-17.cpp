// ============================================================================
// 【说明】：演示利用双重 requires（requires requires(...)）有条件启用类成员函数。
// 【重点】：
//   1. S() requires requires(T t) { t.f(); }
//   2. 仅当模板形参 T 满足特定表达式合法性时，该构造函数才参与重载决议
// ============================================================================
#include <iostream>

template<typename T> struct S {
	S() {
		std::cout << "1.call S()" << std::endl;
	}

	S() requires requires(T t) { t.f(); }  {
		std::cout << "2.call S() requires requires(T t)" << std::endl;
	}
};
struct Arg { void f(); };

int main()
{
    S<int> s1;
    S<Arg> s2;
}