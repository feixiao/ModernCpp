// ============================================================================
// 【说明】：演示部分显式指定模板参数（Explicitly Specified Template Arguments）的推导规则。
// 【重点】：
//   1. template<class T1, class T2> void foo(T1, T2)
//   2. foo<int>(5, 6.8)：T1 显式指定为 int，T2 由实参 6.8 自动推导为 double
// ============================================================================
template<class T1, class T2>
void foo(T1, T2) {}

int main()
{
	foo<int>(5, 6.8);
}
