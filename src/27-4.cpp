// ============================================================================
// 【说明】：演示 C++11 对 constexpr 函数体内部语法的严格限制（仅允许单一 return 语句等）。
// 【重点】：
//   1. C++11 constexpr 函数体内不能包含多条语句、循环或局部变量赋值
//   2. abs2 必须依赖三元运算符条件表达式编写，展示 C++11 初期 constexpr 的局限性
// ============================================================================
constexpr void foo()
{
}

constexpr int next(int x)
{
	return ++x;
}

int g()
{
	return 42;
}

constexpr int f()
{
	return g();
}

constexpr int max_unsigned_char2();
enum {
	max_uchar = max_unsigned_char2()
}

constexpr int abs2(int x)
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
