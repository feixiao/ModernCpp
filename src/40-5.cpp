// ============================================================================
// 【说明】：演示嵌套类型别名（typename T::X）在函数返回类型与形参中的 SFINAE 筛选。
// 【重点】：
//   1. typename A<T>::X 当 T 没有内嵌类型 X 时，该函数重载被静默剔除，顺利调用 foo(...)
// ============================================================================
template <class T> struct A { using X = typename T::X; };
template <class T> typename T::X foo(typename A<T>::X);
template <class T> void foo(...) { }
template <class T> auto bar(typename A<T>::X) -> typename T::X;
template <class T> void bar(...) { }

int main()
{
	foo<int>(0);
	bar<int>(0);
}
