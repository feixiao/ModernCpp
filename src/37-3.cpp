// ============================================================================
// 【说明】：演示 constexpr 指针函数返回值作为指针非类型模板实参。
// 【重点】：
//   1. constexpr int* foo() { return &v; } template<const int*> struct X {};
//   2. 静态全局变量的地址在编译期已知，可以经 constexpr 函数包装后传给模板
// ============================================================================
int v = 42;
constexpr int* foo() { return &v; }
template<const int*> struct X {};

int main()
{
	X<foo()> x;
}
