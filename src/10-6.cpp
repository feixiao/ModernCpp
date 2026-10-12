// ============================================================================
// 【说明】：演示 C++11 = delete 在继承体系中禁止特定参数重载调用的机制。
// 【重点】：
//   1. void foo(long &) = delete; 显式删除针对 long& 的重载版本
//   2. 配合 using Base::foo 导出基类接口时，依然保留 delete 效果，防止派生类意外产生隐式类型转换调用
// ============================================================================
class Base {
//	void foo(long &);
public:
	void foo(long &) = delete;	// 删除foo(long &)函数
	void foo(int) {}
};

class Derived : public Base {
public:
	using Base::foo;
	void foo(const char *) {}
};

int main()
{
	Derived d;
	d.foo("hello");
	d.foo(5);
}
