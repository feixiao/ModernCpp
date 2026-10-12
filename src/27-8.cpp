// ============================================================================
// 【说明】：演示 C++17 允许 Lambda 表达式隐式/显式为 constexpr。
// 【重点】：
//   1. 只要闭包满足字面量类型规则，Lambda 表达式可在编译期常量求值上下文直接调用
//   2. 数组大小可直接初始化为 auto get_size = [](int i){ return i * 2; }; char buffer2[get_size(5)];
// ============================================================================
constexpr int foo()
{
	return []() { return 58; }();
}

auto get_size = [](int i) { return i * 2; };
char buffer1[foo()] = { 0 };
char buffer2[get_size(5)] = { 0 };
