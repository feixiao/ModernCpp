// ============================================================================
// 【说明】：演示 C++11 = delete 显式删除函数实现不可拷贝类（NonCopyable）。
// 【重点】：
//   1. NonCopyable(const NonCopyable&) = delete 删除拷贝构造
//   2. operator=(const NonCopyable&) = delete 删除拷贝赋值
//   3. 相比 C++98 private 方案更干净、语义清晰，并在编译期给出更精准的删除报错
// ============================================================================
class NonCopyable
{
public:
	NonCopyable() = default;                       // 显式添加默认构造函数
	NonCopyable(const NonCopyable&) = delete;      // 显式删除拷贝构造函数
	NonCopyable& operator=(const NonCopyable&) = delete;	// 显式删除拷贝赋值运算符函数
};

int main()
{
	NonCopyable a, b;
	a = b;			//编译失败，拷贝赋值运算符已被删除
}
