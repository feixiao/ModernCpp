// ============================================================================
// 【说明】：演示传统 C++ 命名空间（namespace）的基本声明、作用域及 using 指令。
// 【重点】：
//   1. 区分不同命名空间中的同名函数 S1::foo() 与 S2::foo()
//   2. using namespace S1 引入指定命名空间符号后，可直接调用 foo()
// ============================================================================
#include <cstdio>


namespace S1 {
	void foo() {
		printf("%s\n", __FUNCTION__);
	}
}

namespace S2 {
	void foo() {
		printf("%s\n", __FUNCTION__);
	}
}

using namespace S1;

int main()
{
	foo();
	S2::foo();
}
