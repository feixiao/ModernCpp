// ============================================================================
// 【说明】：演示多重继承基类列表中的形参包展开（多继承混入 Mixin 模式）。
// 【重点】：
//   1. template<class ...Args> class derived : public Args...
//   2. derived(const Args& ...args) : Args(args)... 初始化所有基类
// ============================================================================
#include <iostream>

template<class ...Args>
class derived : public Args...
{
public:
	derived(const Args& ...args) : Args(args)... {}
};

class base1
{
public:
	base1() {}
	base1(const base1&) 
	{
		std::cout << "copy ctor base1" << std::endl;
	}
};

class base2
{
public:
	base2() {}
	base2(const base2&)
	{
		std::cout << "copy ctor base2" << std::endl;
	}
};

int main()
{
	base1 b1;
	base2 b2;
	derived<base1, base2> d(b1, b2);
}
