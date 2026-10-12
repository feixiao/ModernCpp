// ============================================================================
// 【说明】：演示 C++17 [[fallthrough]] 属性显式消除 switch-case 贯穿警告。
// 【重点】：
//   1. case 分支故意不写 break 并向下一个 case 贯穿执行时，标注 [[fallthrough]];
//   2. 向编译器声明这是有意为之的逻辑，避免报 -Wimplicit-fallthrough 告警
// ============================================================================
void bar() {}
void foo(int a)
{
	switch (a)
	{
	case 0:
		break;
	case 1:
		bar();
		[[fallthrough]];
	case 2:
		bar();
		break;
	default:
		break;
	}
}

int main()
{
	foo(1);
}
