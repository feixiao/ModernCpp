// ============================================================================
// 【说明】：演示普通值传递转发（normal_forwarding）在多层调用中的类型退化缺陷。
// 【重点】：
//   1. 普通转发函数 template<class T> void normal_forwarding(T t) 会按值复制参数
//   2. 无法保留实参最初的左值/右值和 const 修饰符属性
// ============================================================================
#include <iostream>
#include <string>

template<class T>
void show_type(T t)
{
	std::cout << typeid(t).name() << std::endl;
}

template<class T>
void normal_forwarding(T t)
{
	show_type(t);
}

int main()
{
	std::string s = "hello world";
	normal_forwarding(s);
}
