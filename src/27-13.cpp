// ============================================================================
// 【说明】：演示 if constexpr 丢弃分支中调用非本类型支持方法不会引发语法编译报错。
// 【重点】：
//   1. 当 T 为 int 时，t.c_str() 所在分支在编译期被丢弃，编译器不检查该分支合法性
//   2. 彻底替代了传统的 SFINAE 复杂标签分派技巧
// ============================================================================
#include <iostream>
#include <string>
#include <type_traits>

template<class T> auto any2i(T t)
{
	if constexpr (std::is_same<T, std::string>::value && T::npos == -1) {
		return atoi(t.c_str());
	}
	else {
		return t;
	}
}

int main()
{
	std::cout << any2i(std::string("6")) << std::endl;
	std::cout << any2i(6) << std::endl;
}
