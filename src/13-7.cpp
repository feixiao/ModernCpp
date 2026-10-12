// ============================================================================
// 【说明】：演示继承构造函数与模板构造函数重载决议的相互作用。
// 【重点】：
//   1. 基类包含模板构造函数和普通参数构造函数
//   2. 派生类通过 using Base::Base 继承后，与派生类本地特有构造函数共同参与匹配
// ============================================================================
#include <iostream>

struct Base {
	Base() = default;
	template<typename T> Base(T, typename T::type = 0)
	{
		std::cout << "Base(T, typename T::type)" << std::endl;
	}
	Base(int) { std::cout << "Base(int)" << std::endl; }
};

struct Derived : Base {
	using Base::Base;
	Derived(int) { std::cout << "Derived(int)" << std::endl; }
};

int main()
{
	Derived d(42L);
}
