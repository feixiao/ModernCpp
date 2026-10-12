// ============================================================================
// 【说明】：演示 C++14 大幅放宽 constexpr 函数体限制（允许局部变量、分支与循环）。
// 【重点】：
//   1. constexpr 函数内部允许声明局部变量、执行 while/for 循环和 if-else 复杂分支
//   2. constexpr int sum(int x) 可以用常规循环累加并在编译期计算 buffer1[sum(5)]
// ============================================================================
constexpr int abs(int x)
{
	if (x > 0) {
		return x;
	} else {
		return -x;
	}
}

constexpr int sum(int x)
{
	int result = 0;
	while (x > 0)
	{
		result += x--;
	}
	return result;
}

char buffer1[sum(5)] = { 0 };
char buffer2[abs(-5)] = { 0 };