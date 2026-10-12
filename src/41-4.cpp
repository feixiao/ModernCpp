// ============================================================================
// 【说明】：演示 C++20 函数模板中四种引入约束形式的混用（约束类形参、auto约束、前置与后置 requires 子句）。
// 【重点】：
//   1. template <ConstType T>（类型形参约束）
//   2. requires std::is_pointer_v<T>（前置 requires 约束模板参数）
//   3. foo(IntegralType auto)（简写函数模板约束）
//   4. requires std::is_same_v<T, char * const>（后置 requires 进一步约束）
// ============================================================================
template <class C>
concept ConstType = std::is_const_v<C>;

template <class C>
concept IntegralType = std::is_integral_v<C>;

template <ConstType T>
requires std::is_pointer_v<T>
void foo(IntegralType auto) requires std::is_same_v<T, char * const> {}
