// ============================================================================
// 【说明】：演示 C++20 调整聚合类定义：禁止任何用户声明的构造函数（包含 =default 和 =delete）。
// 【重点】：
//   1. C++20 规则下，struct X { X() = default; }; 不再被视为聚合类
//   2. struct Y { Y() = delete; }; 同样失去聚合类属性，std::is_aggregate_v 变为 false
// ============================================================================
#include <iostream>
struct X {
	X() = default;
};

struct Y {
	Y() = delete;
};

int main() {
	std::cout << std::boolalpha 
		<< "std::is_aggregate_v<X> : " << std::is_aggregate_v<X> << std::endl
		<< "std::is_aggregate_v<Y> : " << std::is_aggregate_v<Y> << std::endl;
}
