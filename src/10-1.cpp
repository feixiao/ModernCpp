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
	// 手写空构造函数会破坏类的平凡性，即使函数体为空也不例外
	// 手写空构造函数，即使函数体为空，也会破坏类的平凡性
	// 这里手写了空构造函数 Trivial() {}，因此类 Trivial 不再是平凡类，即 std::is_trivial_v<Trivial> 将为 false。
	// 通过删除手写空构造函数或使用 = default 可以恢复类的平凡性
	// 平凡类有什么用？
	//   1. 可以使用 memcpy 等底层优化手段进行高效拷贝
	//   2. 可以保证类的默认构造函数是编译器生成的，避免额外开销
	//   3. 有助于与 C 语言接口的兼容性
	
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
