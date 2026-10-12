// ============================================================================
// 【说明】：演示虚函数重写中 noexcept 异常规范的协变与逆变规则约束。
// 【重点】：
//   1. 基类若是普通虚函数，派生类可以重写为更严格的 foo() noexcept
//   2. 反之若基类虚函数是 noexcept，派生类绝不允许放宽承诺重写为可能抛异常的版本
// ============================================================================
class Base {
public:
	virtual void foo() noexcept {}
};
class Derived : public Base {
public:
	void foo() override {};
};

/*

class Base {
public:
	virtual void foo() {}
};
class Derived : public Base {
public:
	void foo() noexcept override {};
};

*/