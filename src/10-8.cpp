// ============================================================================
// 【说明】：演示通过删除 operator new 禁止类在堆上动态分配内存。
// 【重点】：
//   1. void * operator new(std::size_t) = delete;
//   2. 允许定义栈对象（type auto_var）、全局和静态对象，但在使用 new type 堆分配时产生编译报错
// ============================================================================
struct type 
{
	void * operator new(std::size_t) = delete;
};

type global_var;
int main()
{
	static type static_var;
	type auto_var;
	type *var_ptr = new type;	// 编译失败，该类的new已被删除
}
