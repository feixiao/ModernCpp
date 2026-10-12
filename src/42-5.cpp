// ============================================================================
// 【说明】：演示 C++14 变量模板（Variable Templates）直接定义泛型常量变量。
// 【重点】：
//   1. template<class T> constexpr T PI = static_cast<T>(3.1415926535897932385L);
//   2. 直接使用 PI<float> 获取指定浮点精度的常量，语法精炼优美
// ============================================================================
#include <iostream>

template<class T>
constexpr T PI = static_cast<T>(3.1415926535897932385L);
int main()
{
	std::cout << PI<float> << std::endl;
}
