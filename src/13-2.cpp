// ============================================================================
// 【说明】：演示 using 声明引入基类成员函数重载版本的基本作用域规则。
// 【重点】：
//   1. 派生类声明 foo(char*) 会隐藏基类的 foo(int)
//   2. using Base::foo; 将基类所有同名重载版本引入派生类作用域共同参与重载决议
// ============================================================================
class Base {
public:
	void foo(int) {}
};

class Derived : public Base {
public:
	using Base::foo;
	void foo(char*) {}
};

int main()
{
	Derived d;
	d.foo(5);
}
