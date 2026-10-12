// ============================================================================
// 【说明】：演示 C++17 单参数 static_assert（省略错误描述字符串）。
// 【重点】：
//   1. C++17 允许 static_assert(condition); 省略第二参数字符串
//   2. 简化短小精炼的断言书写，未满足时由编译器自动打印表达式内容
// ============================================================================

#include <type_traits>

class A {
};

class B : public A {
};

class C {
};

template<class T>
class E {
	static_assert(std::is_base_of<A, T>::value);
};

int main(int argc, char *argv[])
{
 	E<C> x;							// 使用正确，但由于A不是C的基类，会触发失败断言
 	static_assert(sizeof(int) < 4);	// 使用正确，但表达式返回false，会触发失败断言
}
