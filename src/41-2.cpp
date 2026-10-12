// ============================================================================
// 【说明】：演示 C++20 概念（concept）与类型约束（Type Constraint）的基本定义与使用。
// 【重点】：
//   1. template <class C> concept IntegerType = std::is_integral_v<C>;
//   2. template <IntegerType T> struct X {}; 一目了然限制 T 必须满足整型约束
// ============================================================================
template <class C>
concept IntegerType = std::is_integral_v<C>;

template <IntegerType T>
struct X {};
