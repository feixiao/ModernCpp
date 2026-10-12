// ============================================================================
// 【说明】：演示非类型模板形参包（Non-type Template Parameter Pack）。
// 【重点】：
//   1. template<int ...Args> void foo1() 接收一串整型常量序列
//   2. 实例化：foo1<1, 2, 5, 7, 11>()，用于编译期序列如 std::integer_sequence
// ============================================================================
template<int ...Args>
void foo1() {};

template<int ...Args>
class bar1 {};

int main()
{
	foo1<1, 2, 5, 7, 11>();
	bar1<1, 5, 8> b;
}
