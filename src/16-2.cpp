// ============================================================================
// 【说明】：演示 C++11 override 说明符在虚函数签名不匹配时的精准编译期拦截。
// 【重点】：
//   1. 在成员函数末尾标注 override
//   2. 编译器强校验基类是否存在同签名的虚函数；若拼写错误或参数微调，直接报编译错误
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
	// 使用 override 说明符可以让编译器在虚函数签名不匹配时报错，避免静默隐藏 Bug
	virtual void sone_func() override {}
	// 编译器会报错，提示 sone_func 并没有正确重写基类的虚函数 some_func
	virtual void foo(int &x) override {}
	virtual void bar() override {}
	virtual void baz() override {}
};
