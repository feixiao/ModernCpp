// ============================================================================
// 【说明】：演示委托构造函数与泛型模板构造函数结合支持多类型容器转化的技巧。
// 【重点】：
//   1. 私有模板构造函数 template<class T> X(T first, T last) 统一基于迭代器初始化
//   2. 公共构造函数 X(vector&) 和 X(deque&) 统一委托给该模板构造函数
// ============================================================================
#include <vector>
#include <list>
#include <deque>

class X {
	template<class T> X(T first, T last) : l_(first, last) { }
	std::list<int> l_;
public:
	X(std::vector<short>&);
	X(std::deque<int>&);
};
X::X(std::vector<short>& v) : X(v.begin(), v.end()) { }
X::X(std::deque<int>& v) : X(v.begin(), v.end()) { }

int main()
{
	std::vector<short> a{ 1,2,3,4,5 };
	std::deque<int> b{ 1,2,3,4,5 };
	X x1(a);
	X x2(b);
}
