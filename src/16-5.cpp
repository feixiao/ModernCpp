// ============================================================================
// 【说明】：演示 C++11 final 说明符修饰类以完全禁止类被继承（终端类）。
// 【重点】：
//   1. class Base final { ... };
//   2. class Derived : public Base 试图继承 final 类时，直接触发编译错误
// ============================================================================
class Base final {
public:
	virtual void foo(int x) {}

};

class Derived : public Base {
public:
	void foo(int x) {};
};
