// ============================================================================
// 【说明】：演示 C++17 if 语句带初始化器（if with initializer）的基本语法。
// 【重点】：
//   1. if (bool b = foo(); b) 语法将局部变量 b 的生命周期紧凑限定在 if-else 块内
//   2. 防止临时变量泄漏污染外部函数作用域
// ============================================================================
#include <iostream>
bool foo()
{
	return true;
}
int main()
{
	if (bool b = foo(); b) {
		std::cout << std::boolalpha << "good! foo()=" << b << std::endl;
	}
}
