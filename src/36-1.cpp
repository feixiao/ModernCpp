// ============================================================================
// 【说明】：演示模板模板参数（Template Template Parameter）的基本概念。
// 【重点】：
//   1. template <template <typename> class T> struct B {};
//   2. B 接收的参数本身必须是一个类模板（如 A），而非具体类型 A<int>
// ============================================================================
template <typename T> struct A {};
template <template <typename> class T> struct B {};
int main()
{
	B<A> ba;
}
