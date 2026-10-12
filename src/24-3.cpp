// ============================================================================
// 【说明】：演示 C++98 传统使用 std::rel_ops 命名空间通过 < 自动扩展其它关系运算符的局限。
// 【重点】：
//   1. 传统依靠 std::rel_ops 会在全局带入容易引发歧义的通用运算符模板
//   2. 突显 C++20 <=> 原生重写和逆序候选运算符（rewritten candidates）的优越性
// ============================================================================
#include <string>
#include <utility>
class CIString2 {
public:
	CIString2(const char* s) : str_(s) {}

	bool operator < (const CIString2& b) const {
		return ci_compare(str_.c_str(), b.str_.c_str()) < 0;
	}
private:
	std::string str_;
};

using namespace std::rel_ops;

int main()
{
    CIString2 s1{ "hello" }, s2{ "world" };
    bool r = s1 >= s2;
}
