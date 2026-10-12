// ============================================================================
// 【说明】：演示原生定长数组聚合类模板的 CTAD 推导。
// 【重点】：
//   1. template <class T, size_t N> struct A { T array[N]; };
//   2. A a{ {1, 2, 3} }; 从初始化列表中推导出 T=int, N=3
// ============================================================================
template <class T, std::size_t N>
struct A {
	T array[N];
};
A a{ {1, 2, 3} };

template <typename T>
struct B {
	T array[2];
};
B b = { 0, 1 };
