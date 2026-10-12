// ============================================================================
// 【说明】：演示 C++17 else if 分支中连续使用初始化器的级联结构。
// 【重点】：
//   1. if (bool b = foo(); b) ... else if (bool b1 = bar(); b1)
//   2. 各分支按需声明局部条件判断变量，层级分明
// ============================================================================
#include <iostream>
bool foo()
{
	return false;
}
bool bar()
{
	return true;
}
int main()
{
	if (bool b = foo(); b) {
		std::cout << std::boolalpha << "foo()=" << b << std::endl;
	}
	else if (bool b1 = bar(); b1) {
		std::cout << std::boolalpha 
			<< "foo()=" << b
			<< ", bar()=" << b1 << std::endl;
	}
}
