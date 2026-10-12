// ============================================================================
// 【说明】：演示 C++20 三路比较运算符（Spaceship Operator: <=>）与 = default 自动合成比较。
// 【重点】：
//   1. auto operator <=> (const D&) const = default;
//   2. 编译器自动按基类和派生类数据成员声明顺序合成字典序比较
//   3. 自动推导并生成 ==, !=, <, <=, >, >= 全部六个关系运算符
// ============================================================================
#include <compare>

struct B 
{
	int a;
	long b;
	auto operator <=> (const B&) const = default;
};

struct D : B 
{
	short c;
	auto operator <=> (const D&) const = default;
};

int main()
{
    D x1, x2;
    std::cout << typeid(decltype(x1 <=> x2)).name();
}