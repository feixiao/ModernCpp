// ============================================================================
// 【说明】：对比手写默认构造函数与 C++11 = default 显式默认化对平凡性（Trivial）的影响。
// 【重点】：
//   1. NonTrivial() {} 会丧失平凡属性（std::is_trivial_v 为 false）
//   2. Trivial() = default 指示编译器合成默认构造函数，保留类的平凡属性（std::is_trivial_v 为 true）
// ============================================================================
class NonTrivial
{
	int i;
public:
	NonTrivial(int n) : i(n), j(n) {}
	NonTrivial() {}
	int j;
};

class Trivial
{
	int i;
public:
	Trivial(int n) : i(n), j(n) {}
	Trivial() = default;
	int j;
};

int main()
{
	Trivial a(5);
	Trivial b;
	b = a;
	std::cout << "std::is_trivial_v<Trivial>   : " << std::is_trivial_v<Trivial> << std::endl;
	std::cout << "std::is_trivial_v<NonTrivial> : " << std::is_trivial_v<NonTrivial> << std::endl;
}
