// ============================================================================
// 【说明】：演示别名模板传入模板模板参数时的匹配与展开行为。
// 【重点】：
//   1. template <typename T> using A = int;
//   2. 别名模板同样可以作为合法的模板模板实参传递给 struct B
// ============================================================================
template <typename T> using A = int;
template <template <typename> class T> struct B {};
int main()
{
	B<A> ba;
}
