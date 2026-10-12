// ============================================================================
// 【说明】：演示 C++11 decltype 推导依赖类型的潜在缺陷（无法使用默认构造推导表达式）。
// 【重点】：
//   1. 如果自定义类型没有默认构造函数，decltype(t1 + t2) 在某些求值构造场景会受限
//   2. 为 C++14 引入纯 auto 返回类型推导以及 std::declval 的必要性提供了依据
// ============================================================================
class IntWrap {
public:
	IntWrap(int n) : n_(n) {}
	IntWrap operator+ (const IntWrap& other)
	{
		return IntWrap(n_ + other.n_);
	}
private:
	int n_;
};

int main() {
	sum2(IntWrap(1), IntWrap(2));	// 编译失败，IntWrap没有默认构造函数
}
