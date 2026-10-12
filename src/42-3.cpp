// ============================================================================
// 【说明】：演示 C++14 之前通过类模板内静态常量成员存储泛型常量的传统模式。
// 【重点】：
//   1. template<class T> struct PI { static constexpr T value = ...; };
//   2. 作为 42-5 中 C++14 变量模板（Variable Templates）的对比代码
// ============================================================================
#include <iostream>

template<class T>
struct PI {
	static constexpr T value = static_cast<T>(3.1415926535897932385);
};

int main()
{
	std::cout << PI<float>::value << std::endl;
}
