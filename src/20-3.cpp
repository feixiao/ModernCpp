// ============================================================================
// 【说明】：演示结构化绑定解包普通结构体（Struct）的非静态公有成员。
// 【重点】：
//   1. struct BindTest { int a; std::string b; };
//   2. auto[x, y] = bt; 直接按结构体内成员声明顺序完成字段解构
// ============================================================================
#include <iostream>
#include <string>

struct BindTest {
	int a = 42;
	std::string b = "hello structured binding";
};

int main()
{
	BindTest bt; // 创建 BindTest 结构体实例
	// 使用结构化绑定解包 bt 的非静态公有成员，x 和 y 自动获得对应字段的类型与值
	auto[x, y] = bt;
	std::cout << "x=" << x << " y=" << y << std::endl;
}
