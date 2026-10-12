// ============================================================================
// 【说明】：演示 C++98 explicit 关键字显式禁止单参数构造函数的隐式转换。
// 【重点】：
//   1. explicit SomeString(int alloc_size);
//   2. 阻止 PrintStr(58) 误传入数字，强制只能写显式构造 PrintStr(SomeString(58))
// ============================================================================
class SomeString {
public:
	SomeString(const char * p) : str_(_strdup(p)) {}
	explicit SomeString(int alloc_size) : str_((char *)malloc(alloc_size)) {}
	~SomeString() { free(str_); }
private:
	char *str_;
	friend void PrintStr(const SomeString& str);
};

int main()
{
	PrintStr("hello world");
PrintStr(58);               // 编译失败
	PrintStr(SomeString(58));
}
