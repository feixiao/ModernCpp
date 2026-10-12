// ============================================================================
// 【说明】：演示 C++17 模板模板实参匹配放宽规则（P0522R0）。
// 【重点】：
//   1. 接受 template<template<typename> class T> 的外层模板
//   2. 允许传入带默认参数的 template<class, class = int> struct bar 作为实参
// ============================================================================
template <template <typename> class T, class U> void foo()
{
	T<U> n;
}
template <class, class = int> struct bar {};

int main()
{
	foo<bar, double>();
}
