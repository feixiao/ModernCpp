// ============================================================================
// 【说明】：演示 C++20 原子约束（Atomic Constraints）的规范化与从属（Subsumption）比较规则。
// 【重点】：
//   1. 编译器在重载决议时通过约束规范化分析两个 requires 子句的强弱从属包含关系
// ============================================================================
template <int N> constexpr bool Atomic = true;
template <int N> concept C = Atomic<N>;
template <int N> concept Add1 = C<N + 1>;
template <int N> concept AddOne = C<N + 1>;
template <int M> void f()
requires Add1<2 * M> {};
template <int M> void f()
requires AddOne<2 * M> && true {};

f<0>(); // 编译成功
