// ============================================================================
// 【说明】：演示 C++11 final 说明符禁止虚函数在派生类中被进一步重写（Override）。
// 【重点】：
//   1. Derived 中声明 void foo(int x) final;
//   2. 子类 Derived2 试图再次重写 foo(int x) 时，触发编译错误
// ============================================================================
class Base {
public:
	virtual void foo(int x) {}

};

class Derived : public Base {
public:
	// 声明 foo(int x) 为 final，禁止在派生类中被进一步重写
	void foo(int x) final {};
};

class Derived2 : public Derived {
public:
	void foo(int x) {}; // 编译错误，Derived 中的 foo(int x) 已经被声明为 final
};
