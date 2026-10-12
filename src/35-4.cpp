// ============================================================================
// 【说明】：演示模式匹配包展开（Pack Expansion）与逐元素函数应用。
// 【重点】：
//   1. foo(baz(&args, args)...) 中省略号位于模式表达式外层
//   2. 编译器将模式对形参包中每个元素依次应用并展开为逗号分隔列表
// ============================================================================
#include <iostream>

template<class T, class U>
T baz(T t, U u)
{
	std::cout << t << ":" << u << std::endl;
	return t;
}

template<class ...Args>
void foo(Args ...args) {}

template<class ...Args>
class bar {
public:
	bar(Args ...args)
	{
		foo(baz(&args, args)...);
	}
};

int main()
{
	bar<int, double, unsigned int> b(1, 5.0, 8);
}
