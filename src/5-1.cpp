// ============================================================================
// 【说明】：演示 C++11 尾置返回类型（trailing return type）的基本语法与函数指针声明。
// 【重点】：
//   1. 传统返回函数指针写法复杂晦涩（如 bar foo1() 或 typedef）
//   2. auto foo2() -> int(*)(int) 使用 auto + 尾置箭头清晰表达返回值是函数指针类型
// ============================================================================
int bar_impl(int x)
{
	return x;
}

typedef int(*bar)(int);
bar foo1()
{
	return bar_impl;
}

auto foo2()->int(*)(int)
{
	return bar_impl;
}

int main() {
	auto func = foo2();
	func(58);
}
