// ============================================================================
// 【说明】：演示将否定表达式封装在独立命名 concept（not_sad）中以恢复偏序从属匹配。
// 【重点】：
//   1. concept not_sad = !sad<T>;
//   2. 随后 (not_sad<T>) && true 成功建立比 (not_sad<T>) 更特化的从属包含关系，消除了二义性
// ============================================================================
template <class T> concept not_sad = !sad<T>;
template <class T> int f2(T) requires (not_sad<T>) { return 3; };
template <class T> int f2(T) requires (not_sad<T>) && true  { return 4; };

f2(0);
