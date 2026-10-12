// ============================================================================
// 【说明】：演示 C++11 字面量类型（Literal Type）与 constexpr 构造函数。
// 【重点】：
//   1. constexpr X() : x1(5) {}
//   2. 构造函数声明为 constexpr 后，该类成为字面量类型，其实例 x 可用于编译期计算
// ============================================================================
class X {
public:
	constexpr X() : x1(5) {}
	constexpr X(int i) : x1(i) {}
	constexpr int get() const
	{
		return x1;
	}
private:
	int x1;
};

constexpr X x;
char buffer[x.get()] = { 0 };