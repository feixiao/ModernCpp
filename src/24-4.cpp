// ============================================================================
// 【说明】：演示具有传统比较运算符的旧类型如何与 C++20 <=> std::strong_ordering 兼容桥接。
// 【重点】：
//   1. 内部成员 Legacy 仅重载了传统的 == 和 <
//   2. 外层类 TreeWay 可以声明 std::strong_ordering operator<=> = default，编译器自动桥接旧运算符
// ============================================================================
#include <compare>
struct Legacy {
	int n;
	bool operator==(const Legacy& rhs) const
	{
		return n == rhs.n;
	}
	bool operator<(const Legacy& rhs) const
	{
		return n < rhs.n;
	}
};

struct TreeWay {
	Legacy m;
	std::strong_ordering operator<=>(const TreeWay &) const = default;
};

int main()
{
    TreeWay t1, t2;
    bool r = t1 < t2;
}
