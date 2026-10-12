// ============================================================================
// 【说明】：演示 C++17 编译期条件分支 if constexpr 与普通运行时 if 的区别。
// 【重点】：
//   1. if constexpr (condition) 的条件必须是编译期常量表达式
//   2. 传入非常量形参 int i 导致编译失败；必须传入如 sizeof(int) > sizeof(char) 等常量表达式
// ============================================================================
void check1(int i)
{
	if constexpr (i > 0) {					// 编译失败，不是常量表达式
		std::cout << "i > 0" << std::endl;
	}
	else {
		std::cout << "i <= 0" << std::endl;
	}
}

void check2()
{
	if constexpr (sizeof(int) > sizeof(char)) {
		std::cout << "sizeof(int) > sizeof(char)" << std::endl;
	}
	else {
		std::cout << "sizeof(int) <= sizeof(char)" << std::endl;
	}
}
