// ============================================================================
// 【说明】：演示 C++20 [[no_unique_address]] 属性实现空基类/空成员优化（EBCO）。
// 【重点】：
//   1. 传统的空结构体成员因需要独立地址通常至少占据 1 字节并触发内存对齐对齐膨胀
//   2. [[no_unique_address]] Empty e 允许编译器复用其地址空间，使其占用 0 字节开销
// ============================================================================
#include <iostream>
struct Empty {};

struct X {
	int i;
	Empty e;
};

/*

struct X {
	int i;
	[[no_unique_address ]]Empty e;
};

struct X {
    int i;
    [[no_unique_address]] Empty e, e1;
};

struct Empty {}; 
struct Empty1 {};

struct X {
	int i;
	[[no_unique_address]] Empty e;
	[[no_unique_address]] Empty1 e1;
};

*/

int main()
{
    std::cout << "sizeof(X) = " << sizeof(X) << std::endl
    << "X::i address = " <<  &((X*)0)->i << std::endl
	<< "X::e address = " << &((X*)0)->e;

    /*
    
    std::cout << "sizeof(X) = " << sizeof(X) << std::endl
	<< "X::i address = " <<  &((X*)0)->i << std::endl
	<< "X::e address = " << &((X*)0)->e << std::endl
	<< "X::e1 address = " << &((X*)0)->e1 << std::endl;

    */
}
