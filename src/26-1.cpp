// ============================================================================
// 【说明】：演示 C++17 内联变量（inline variables）在类定义内直接初始化静态非 const 成员。
// 【重点】：
//   1. inline static std::string text{"hello"};
//   2. 解决 C++17 之前静态成员必须在类外单独一个 .cpp 文件中进行定义的头文件单一定义原则（ODR）限制
// ============================================================================
#include <iostream>
#include <string>

class X {
public:
	inline static std::string text{"hello"};
};

int main()
{
	X::text += " world";
	std::cout << X::text << std::endl;
}
