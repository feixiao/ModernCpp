// ============================================================================
// 【说明】：演示 C++11 static_assert 编译期断言的基本用法与常量表达式要求。
// 【重点】：
//   1. static_assert(std::is_base_of<A, T>::value, "提示信息") 进行编译期类型检查
//   2. 断言条件必须是编译期常量表达式（传入运行时 argc > 0 将直接编译报错）
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
	static_assert(std::is_base_of<A, T>::value, "T is not base of A");
};

int main(int argc, char *argv[])
{
    static_assert(argc > 0, "argc > 0");	// 使用错误，argc>0不是常量表达式
    E<C> x;							        // 使用正确，但由于A不是C的基类，所以触发断言
    static_assert(sizeof(int) >= 4,		    // 使用正确，表达式返回真，不会触发失败断言
        "sizeof(int) >= 4");
    E<B> y;							        // 使用正确，A是B的基类，不会触发失败断言
}
