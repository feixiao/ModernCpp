// ============================================================================
// 【说明】：演示关系相等运算符（==）在概念定义中的规范化与偏序决议。
// 【重点】：
//   1. 比较使用命名概念封装条件对编译器约束消歧义的关键影响
// ============================================================================
template <class T> int f3(T) requires (not_sad<T> == true) { return 5; };
template <class T> int f3(T) requires (not_sad<T> == true) && true  { return 6; };

f3(0);

template <class T> concept not_sad_is_true = !sad<T> == true;
template <class T> int f4(T) requires (not_sad_is_true<T>) { return 7; };
template <class T> int f4(T) requires (not_sad_is_true<T>) && true  { return 8; };

f4(0);
