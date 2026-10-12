// ============================================================================
// 【说明】：演示自定义类重载 operator new 与 operator delete 时的完整生命周期调用。
// 【重点】：
//   1. 追踪堆分配时 operator new 分配内存 -> 执行构造函数 -> 显式 delete 执行析构 -> operator delete 释放内存
// ============================================================================
#include <iostream>
#include <new>
struct X {
	X() {}
	~X()
	{
		std::cout << "call dtor" << std::endl;
	}
	void* operator new(size_t s)
	{
		return ::operator new(s);
	}

	void operator delete(void* ptr)
	{
		std::cout << "call delete" << std::endl;
		::operator delete(ptr);
	}
};

int main()
{
    X* x = new X;
    delete x;
}
