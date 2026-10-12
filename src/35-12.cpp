// ============================================================================
// 【说明】：演示 sizeof... 运算符在编译期查询形参包中元素的个数。
// 【重点】：
//   1. sizeof...(args) 查询函数形参包大小；sizeof...(Args) 查询模板类型包大小
//   2. 返回 size_t 编译期常量
// ============================================================================
#include <iostream>

template<class ...Args> void foo(Args ...args)
{
	std::cout << "foo sizeof...(args) = " << sizeof...(args) << std::endl;
}

template<class ...Args>
class bar
{
public:
	bar() {
		std::cout << "bar sizeof...(Args) = " << sizeof...(Args) << std::endl;
	}
};

int main()
{
	foo();
	foo(1,2,3);

	bar<> b1;
	bar<int, double> b2;
}
