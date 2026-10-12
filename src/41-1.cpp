// ============================================================================
// 【说明】：演示 C++11 std::enable_if 配合类型萃取（std::is_integral_v）实现模板约束的传统写法。
// 【重点】：
//   1. template <class T, class U = std::enable_if_t<std::is_integral_v<T>>>
//   2. 错误信息冗长且不易阅读，引出 C++20 Concepts（概念）优雅解法
// ============================================================================
template <class T, class U = std::enable_if_t<std::is_integral_v<T>>>
struct X {};

X<int> x1; // 编译成功
X<std::string> x2; // 编译失败
