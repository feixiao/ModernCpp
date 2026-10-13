// ============================================================================
// 【说明】：演示没有 override 说明符时，虚函数重写签名不匹配引发的静默隐藏 Bug。
// 【重点】：
//   1. Derived 误写拼写（sone_func）或改动形参类型（foo(int&)）
//   2. 编译器将其视为新声明的普通函数而非虚函数重写，完全丧失多态性且无警告
// ============================================================================
class Base {
public:
	virtual void some_func() {}
	virtual void foo(int x) {}
	virtual void bar() const {}
	void baz() {}
};

class Derived : public Base {
public:
	virtual void sone_func() {}
	// foo(int &x) 并没有正确重写基类的 foo(int x)，而是新声明了一个普通函数
	virtual void foo(int &x) {}
	virtual void bar() {}
	virtual void baz() {}
};
