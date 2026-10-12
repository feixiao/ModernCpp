// ============================================================================
// 【说明】：演示利用 placement new 与显式析构在非受限联合体中安全切换活跃成员。
// 【重点】：
//   1. 切换到 string：new(&u.x3) std::string("hello world"); 离开时显式 u.x3.~basic_string();
//   2. 切换到 vector：new(&u.x4) std::vector<int>; 离开时显式 u.x4.~vector();
//   3. 这是 std::variant 底层实现机制的基础原理
// ============================================================================
#include <iostream>
#include <string>
#include <vector>

union U
{
	U() {}
	~U() {}
	int x1;
	float x2;
	std::string x3;
	std::vector<int> x4;
};

int main()
{
	U u;
	new(&u.x3) std::string("hello world");
	std::cout << u.x3 << std::endl;
	u.x3.~basic_string();

	new(&u.x4) std::vector<int>;
	u.x4.push_back(58);
	std::cout << u.x4[0] << std::endl;
	u.x4.~vector();
}
