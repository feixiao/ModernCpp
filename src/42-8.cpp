// ============================================================================
// 【说明】：演示在多构造函数显式条件（explicit(bool)）与约束组合时 SFINAE 与 Concepts 的对比。
// 【重点】：
//   1. 结合 C++20 条件 explicit 构造函数
//   2. 展示现代 C++ 概念约束相比传统模板元编程在提升工程代码可读性和编译报错诊断质量上的革命性飞跃
// ============================================================================
// SFINAE版本
template <typename T1, typename T2>
struct pair {
    template <typename U1=T1, typename U2=T2,
        std::enable_if_t<
            std::is_constructible_v<T1, U1> &&
            std::is_constructible_v<T2, U2>
        , int> = 0>
    explicit(!std::is_convertible_v<U1, T1> ||
        !std::is_convertible_v<U2, T2>)
    constexpr pair(U1&&, U2&& );   
};

// 概念版本
template <typename T1, typename T2>
struct pair {
    template <typename U1=T1, typename U2=T2>
        requires std::is_constructible_v<T1, U1> &&
            std::is_constructible_v<T2, U2>
    explicit(!std::is_convertible_v<U1, T1> ||
        !std::is_convertible_v<U2, T2>)
    constexpr pair(U1&&, U2&& );
};
