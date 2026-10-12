// ============================================================================
// 【说明】：演示 C++98 派生类需要手动透传实现基类所有构造函数的代码膨胀痛点。
// 【重点】：
//   1. 派生类 Derived 必须为 Base 的每个构造函数逐一手写转发构造函数
//   2. 引出 13-3 中 C++11 using Base::Base 继承构造函数的简洁语法
// ============================================================================
class Base {
public:
	Base() : x_(0), y_(0.) {};
	Base(int x, double y) : x_(x), y_(y) {}
	Base(int x) : x_(x), y_(0.) {}
	Base(double y) : x_(0), y_(y) {}
	void SomeFunc() {}
private:
	int x_;
	double y_;
};


class Derived : public Base {
public:
	Derived() {};
	Derived(int x, double y) : Base(x, y) {}
	Derived(int x) : Base(x) {}
	Derived(double y) : Base(y) {}
	void SomeFunc() {}
};
