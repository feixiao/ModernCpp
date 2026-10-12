// ============================================================================
// 【说明】：演示 C++11 可变参数模板函数（Variadic Templates）与形参包（Parameter Pack）。
// 【重点】：
//   1. template<class ...Args> void foo(Args ...args)
//   2. 允许接收任意数量、任意类型的实参进行模板推导
// ============================================================================
template<class ...Args>
void foo(Args ...args) {}

int main()
{
	unsigned int x = 8;
    foo();				// foo()
	foo(1);				// foo<int>(int)
	foo(1, 11.7);		// foo<int,double>(int,double)
	foo(1, 11.7, x);	// foo<int,double,unsigned int>(int,double,unsigned int)
}
