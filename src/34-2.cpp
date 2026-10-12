// ============================================================================
// 【说明】：演示单参数构造函数未声明 explicit 时导致的隐式类型转换缺陷。
// 【重点】：
//   1. SomeString(int alloc_size) 原本用于预分配内存
//   2. 但未加 explicit 导致 PrintStr(58) 错误调用能够隐式编译通过
// ============================================================================
#include <iostream>
#include <string.h>

class SomeString {
public:
	SomeString(const char * p) : str_(strdup(p)) {}
	SomeString(int alloc_size) : str_((char *)malloc(alloc_size)) {}
	~SomeString() { free(str_); }
private:
	char *str_;
	friend void PrintStr(const SomeString& str);
};

void PrintStr(const SomeString& str)
{
	std::cout << str.str_ << std::endl;
}

int main()
{
	PrintStr("hello world");
	PrintStr(58);             // 代码写错，却编译成功
}
