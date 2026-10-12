// ============================================================================
// 【说明】：演示手写空构造函数对类“平凡性”（Trivial）的破坏与 std::is_trivial_v 检测。
// 【重点】：
//   1. 一旦用户手写了 Trivial() {}（即使函数体为空），该类就不再具备平凡默认构造函数
//   2. 导致 std::is_trivial_v<Trivial> 为 false，影响 memcpy 等底层优化
//   3. 为 10-4.cpp 中使用 = default 保持平凡性做铺垫
// ============================================================================
class Trivial
{
	int i;
public:
	Trivial(int n) : i(n), j(n) {}
	Trivial() {}
	int j;
};

int main()
{
	Trivial a(5);
	Trivial b;
	b = a;
	std::cout << "std::is_trivial_v<Trivial>   : " 
<< std::is_trivial_v<Trivial> << std::endl;
}
