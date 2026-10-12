// ============================================================================
// 【说明】：演示自定义类手写 <=> 重载实现忽略大小写的字符串比较（CIString）。
// 【重点】：
//   1. 通过返回自定义比较差值，在 C++20 中只写一个 <=> 即可支持与 0 比较判断相等和相对大小
// ============================================================================
#include <compare>
#include <string>

int ci_compare(const char* s1, const char* s2)
{
	while (tolower(*s1) == tolower(*s2++)) {
		if (*s1++ == '\0') {
			return 0;
		}
	}
	return tolower(*s1) - tolower(*--s2);
}

class CIString {
public:
	CIString(const char *s) : str_(s) {}

	std::weak_ordering operator<=>(const CIString& b) const {
		return ci_compare(str_.c_str(), b.str_.c_str()) <=> 0;
	}
private:
	std::string str_;
};

int main()
{
    CIString s1{ "HELLO" }, s2{"hello"};
    std::cout << (s1 <=> s2 == 0); // 输出为true
}

