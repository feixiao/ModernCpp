// ============================================================================
// 【说明】：演示 requires 表达式内部嵌套 requires 子句（Nested Requirement）。
// 【重点】：
//   1. requires std::same_as<decltype((a + b)), int>;
//   2. 嵌套 requires 用于在求值期强行断言某个编译期布尔类型特征必须为 true
// ============================================================================
template <class T>
concept Check = requires(T a, T b) {
	requires std::same_as<decltype((a + b)), int>;
};
