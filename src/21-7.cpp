// ============================================================================
// 【说明】：演示标注 noexcept 的函数若在运行时抛出异常将直接调用 std::terminate。
// 【重点】：
//   1. 即使外部有 try-catch，noexcept 函数内部抛出的异常也不会被外层 catch 捕获
//   2. 违反 noexcept 承诺时，运行时环境立即强制终止程序
// ============================================================================
#include <iostream>
#include <string>

void(*fp)() noexcept = nullptr;
void foo() 
{
	throw(5);
}

int main()
{
	fp = &foo;
	try {
		fp();
	}
	catch (int e)
	{
		std::cout << e << std::endl;
	}
}
