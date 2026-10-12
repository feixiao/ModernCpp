// ============================================================================
// 【说明】：对比实现通用 pair 构造函数：C++11 SFINAE 繁琐写法 vs C++20 Concepts 清晰写法。
// 【重点】：
//   1. SFINAE 版本：借助深层嵌套的 std::enable_if_t、std::is_constructible_v 与默认形参，代码晦涩冗长
//   2. Concepts 版本：使用直接的 requires std::is_constructible_v<...> 子句，清晰明了
// ============================================================================
// SFINAE版本
template <typename T1, typename T2>
struct pair {
    template <typename U1=T1, typename U2=T2,
        std::enable_if_t<
            std::is_constructible_v<T1, U1> &&
            std::is_constructible_v<T2, U2> &&
            std::is_convertible_v<U1, T1> &&
            std::is_convertible_v<U2, T2>
        , int> = 0>
    constexpr pair(U1&&, U2&& );
    
    template <typename U1=T1, typename U2=T2,
        std::enable_if_t<
            std::is_constructible_v<T1, U1> &&
            std::is_constructible_v<T2, U2> &&
            !(std::is_convertible_v<U1, T1> &&
              std::is_convertible_v<U2, T2>)
        , int> = 0>
    explicit constexpr pair(U1&&, U2&& );    
};

// 概念版本
template <typename T1, typename T2>
struct pair {
    template <typename U1=T1, typename U2=T2>
        requires std::is_constructible_v<T1, U1> &&
            std::is_constructible_v<T2, U2> &&
            std::is_convertible_v<U1, T1> &&
            std::is_convertible_v<U2, T2>
    constexpr pair(U1&&, U2&& );
    
    template <typename U1=T1, typename U2=T2>
        requires std::is_constructible_v<T1, U1> &&
            std::is_constructible_v<T2, U2>
    explicit constexpr pair(U1&&, U2&& );    
};
