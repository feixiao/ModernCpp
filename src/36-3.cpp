// ============================================================================
// 【说明】：演示 C++17 允许在模板模板参数中使用 typename 替代 class。
// 【重点】：
//   1. C++17 之前规定必须写 template <typename> class T
//   2. C++17 统一允许写 template <typename> typename T
// ============================================================================
template <typename T> using A = int;
template <template <typename> typename T> struct B {};
int main()
{
	B<A> ba;
}
