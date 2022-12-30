#include <iostream>

namespace Parent {
	namespace Child1
	{
		void foo() { std::cout << "Child1::foo()" << std::endl; }
	}
	

	// 内联命名空间能够把空间内函数和类型导出到父命名空间中，这样即使不指定子命名空间也可以使用其空间内的函数和类型了
	inline namespace Child2
	{
		void foo() { std::cout << "Child2::foo()" << std::endl; }
	}
}

int main()
{
	Parent::Child1::foo();
	Parent::foo();	// Parent::Child2::foo();
}
