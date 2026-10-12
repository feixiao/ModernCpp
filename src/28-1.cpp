// ============================================================================
// 【说明】：演示成员函数链式调用（Fluent API / Method Chaining）在现代 C++ 中的表现。
// 【重点】：
//   1. std::string::replace 每次返回当前对象的引用 *this
//   2. 使得连续调用 .replace(...).replace(...) 可以像流水线一样连贯执行
// ============================================================================
void f2() {
	std::string s = "but I have heard it works even if you don't believe in it";
	s.replace(0, 4, "").replace(s.find("even"), 4, "only").replace(s.find(" don't"), 6, "");
	assert(s == "I have heard it works only if you believe in it"); // OK
}
