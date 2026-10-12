// ============================================================================
// 【说明】：演示 requires 表达式中的复合要求（Compound Requirement: noexcept 与返回类型约束）。
// 【重点】：
//   1. { a.clear() } noexcept;（要求调用不能抛异常）
//   2. { a + b } noexcept -> std::same_as<int>;（要求返回类型必须符合特定的 concept）
// ============================================================================
template <class T>
concept Check = requires(T a, T b) {
	{a.clear()} noexcept;
	{a + b} noexcept -> std::same_as<int>;
};
