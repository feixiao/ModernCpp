// ============================================================================
// 【说明】：演示组合使用 override final 确保特定虚函数实现被冻结封顶。
// 【重点】：
//   1. virtual void log(...) const override final;
//   2. 既确保成功重写了基类接口，又防止下游类再次篡改该关键虚函数行为
// ============================================================================
class Base {
public:
	virtual void log(const char *) const {...}
	virtual void foo(int x) {}

};

class BaseWithFileLog : public Base {
public:
	virtual void log(const char *) const override final {...}
};

class Derived : public BaseWithFileLog {
public:
	void foo(int x) {};
};
