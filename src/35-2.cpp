// ============================================================================
// 【说明】：演示可变参数类模板的声明与任意类型列表实例化。
// 【重点】：
//   1. template<class ...Args> class bar {};
//   2. 支持零个或多个类型实参：bar<>, bar<int>, bar<int, double, unsigned>
// ============================================================================
template<class ...Args>
class bar {};

int main()
{
	bar<> b1;
	bar<int> b2;
	bar<int, double> b3;
	bar<int, double, unsigned int> b4;
}
