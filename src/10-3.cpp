// ============================================================================
// 【说明】：演示派生类中 using Base::foo 引入基类重载函数时的作用域隐藏与匹配行为。
// 【重点】：
//   1. 派生类显式 using Base::foo; 将基类的 foo(int) 带入当前作用域
//   2. d.foo(5) 正确调用基类函数，d.foo("hello") 调用派生类本地特有重载
// ============================================================================
class Base {
	void foo(long &);
public:
	void foo(int) {}
};

class Derived : public Base {
public:
	// 派生类中引入基类的 foo(int) 函数，避免被派生类的 foo(const char*) 隐藏
	using Base::foo;
	// 派生类中定义了 foo(const char*)，如果不使用 using Base::foo;，基类的 foo(int) 将被隐藏
	void foo(const char *) {}
};

int main()
{
	Derived d;
	d.foo("hello");
	d.foo(5);
}
