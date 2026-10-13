// ============================================================================
// 【说明】：演示 C++11 完美转发（Perfect Forwarding）与 std::forward 的原理。
// 【重点】：
//   1. 结合通用引用 T&& 与引用折叠（Reference Collapsing）规则
//   2. static_cast<T&&>(t)（即 std::forward<T>(t)）无损保留实参的左右值特性向底层传递
//   3. 传入左值 s 时推导保持左值引用；传入右值 get_string() 时保持右值引用
// ============================================================================
#include <iostream>
#include <string>

// 显示类型信息的辅助函数
template<class T>
void show_type(T t)
{
	std::cout << typeid(t).name() << std::endl;
}

// 完美转发函数模板
// 完美转发是指函数模板能够将其参数以原有的值类别（左值或右值）完美地转发给另一个函数。
// 相当于传统C++的好处是可以避免不必要的拷贝，提高性能。
template<class T>
void perfect_forwarding(T &&t)
{
	show_type(static_cast<T&&>(t));
}

std::string get_string()
{
	return "hi world";
}

int main()
{
	std::string s = "hello world";
	perfect_forwarding(s);
	perfect_forwarding(get_string());
}
