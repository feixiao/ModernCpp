// ============================================================================
// 【说明】：演示 template<auto> 与模板模板参数结合的泛型非类型参数抽象。
// 【重点】：
//   1. template <template <auto> class T, auto N> void foo()
//   2. 将 auto 统一非类型模板参数推广到更高维度的模板模板抽象
// ============================================================================
template <template <auto> class T, auto N> void foo() 
{ 
	T<N> n;
}
template <auto> struct bar {};

int main()
{
	foo<bar, 5>();
}
