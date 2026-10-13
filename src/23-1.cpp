// ============================================================================
// 【说明】：演示 C++11 空指针字面量 nullptr 及其专用类型 std::nullptr_t 的重载选择机制。
// 【重点】：
//   1. 传统的 NULL 通常被宏定义为 0，会导致在整型与指针重载间产生歧义或误匹配 int
//   2. nullptr 拥有独立的 std::nullptr_t 类型，精准特化匹配 widget<std::nullptr_t>
// ============================================================================
#include <iostream>

template<class T>
struct widget
{
	widget()
	{
		std::cout << "template" << std::endl;
	}
};

template<>
struct widget<std::nullptr_t>
{
	widget()
	{
		std::cout << "nullptr" << std::endl;
	}
};

template<class T>
widget<T>* make_widget(T)
{
	return new widget<T>();
}

int main()
{
	// 调用 make_widget 创建不同类型的 widget 实例，观察重载选择机制
	// 传入整型 0，会匹配模板版本 widget<int>
	auto w1 = make_widget(0);
	auto w2 = make_widget(nullptr); // 传入 nullptr，会匹配特化版本 widget<std::nullptr_t>
}
