// ============================================================================
// 【说明】：演示直接在 requires 子句中使用否定操作符（!）的原子约束判定限制。
// 【重点】：
//   1. requires (!sad<T>) 与 requires (!sad<T>) && true
//   2. 未封装在命名 concept 内的表达式在参与偏序比较时可能无法建立从属关系
// ============================================================================
template <class T> concept sad = false;
template <class T> int f1(T) requires (!sad<T>) { return 1; };
template <class T> int f1(T) requires (!sad<T>) && true {return 2; };

f1(0); // 编译失败
