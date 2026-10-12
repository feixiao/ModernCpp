// ============================================================================
// 【说明】：演示 C++11 constexpr 函数的基本概念与其在编译期常量表达式中的应用。
// 【重点】：
//   1. constexpr int square(int x) { return x * x; }
//   2. 当传入参数为常量时，可在编译期计算求值并直接用于原生定长数组大小：buffer2[square(5)]
// ============================================================================
constexpr int max_unsigned_char()
{
	return 0xff;
}

constexpr int square(int x)
{
	return x * x;
}

constexpr int abs(int x)
{
	return x > 0 ? x : -x;
}

int main()
{
	char buffer1[max_unsigned_char()] = { 0 };
	char buffer2[square(5)] = { 0 };
	char buffer3[abs(-8)] = { 0 };
}
