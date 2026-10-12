// ============================================================================
// 【说明】：演示 C++20 requires 表达式（Requires Expression）的基本简单要求（Simple Requirement）。
// 【重点】：
//   1. concept Check = requires { T().clear(); };
//   2. 仅检查表达式 T().clear() 是否在语法上合法有效，不实际执行代码
// ============================================================================
template <class T>
concept Check = requires {
	T().clear();
};

template <Check T>
struct G {};

G<std::vector<char>> x; // 编译成功
G<std::string> y; // 编译成功
G<std::array<char, 10>> z; // 编译失败
