// ============================================================================
// 【说明】：演示多个同长度形参包的同步并行展开语法。
// 【重点】：
//   1. 涉及两个形参包时的组合表达式同步展开机制
// ============================================================================
template<class ...T>
int baz(T ...t)
{
	return 0;
}

template<class ...Args>
void foo(Args ...args) {}

template<class ...Args>
class bar {
public:
	bar(Args ...args)
	{
		foo(baz(&args...) + args...);
	}
};

int main()
{
	bar<int, double, unsigned int> b(1, 5.0, 8);
}
