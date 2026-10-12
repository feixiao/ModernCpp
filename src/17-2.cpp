// ============================================================================
// 【说明】：演示基于范围的 for 循环中循环变量按值传递（auto n）产生的深拷贝开销。
// 【重点】：
//   1. for (auto n : x) 对容器中每个元素均触发一次拷贝构造函数
//   2. 说明推荐使用 const auto& 或 auto&& 避免非必要复制
// ============================================================================
#include <vector>
struct X
{
	X() { std::cout << "default ctor" << std::endl; }
	X(const X& other) {
		std::cout << "copy ctor" << std::endl;
	}
};

int main()
{
	std::vector<X> x(10);
	std::cout << "for (auto n : x)" << std::endl;
	for (auto n : x) {
	}
	std::cout << "for (const auto &n : x)" << std::endl;
	for (const auto &n : x) {
	}
}
