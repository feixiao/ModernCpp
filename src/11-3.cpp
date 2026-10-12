// ============================================================================
// 【说明】：演示非受限联合体在构造函数中选择性初始化特定非平凡成员的写法。
// 【重点】：
//   1. 构造函数初始化列表中通过 U() : x3() {} 构造 string 成员
//   2. 析构函数必须显式调用当前活动成员的伪析构/显式析构函数 x3.~basic_string()
// ============================================================================
#include <iostream>
#include <string>
#include <vector>

union U
{
	U() : x3() {}
	~U() { x3.~basic_string(); }
	int x1;
	float x2;
	std::string x3;
	std::vector<int> x4;
};

int main()
{
	U u;
	u.x3 = "hello world";
	std::cout << u.x3;
}
