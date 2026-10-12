// ============================================================================
// 【说明】：演示 C++17 __has_include 预处理条件指令探测头文件可用性。
// 【重点】：
//   1. #if __has_include(<optional>) 动态探测编译器是否原生支持 <optional>
//   2. 若不支持则自动降级包含 <experimental/optional>，实现优美的高可移植性代码
// ============================================================================
#if __has_include(<optional>)
#  include <optional>
#  define have_optional 1
#elif __has_include(<experimental/optional>)
#  include <experimental/optional>
#  define have_optional 1
#  define experimental_optional 1
#else
#  define have_optional 0
#endif
