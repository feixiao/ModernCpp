// ============================================================================
// 【说明】：演示 Lambda 表达式捕获列表中的形参包按值捕获与内部展开。
// 【重点】：
//   1. auto lm = [args...]{ foo(&args...); };
//   2. C++11 支持在捕获列表中直接解包捕获外层函数模板的实参包
// ============================================================================
template<class ...Args> void foo(Args ...args) {}

template<class ...Args>
class bar
{
public:
	bar(Args ...args) {
		auto lm = [args ...]{ foo(&args...); };
		lm();
	}
};

int main()
{
	bar<int, double> b2(5, 8.11);
}
