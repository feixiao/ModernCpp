// ============================================================================
// 【说明】：演示继承构造函数严格尊重基类构造函数访问控制权限（私有不可继承）。
// 【重点】：
//   1. Base(int) 是私有的，Base(double) 是公有的
//   2. using Base::Base 只会使派生类能访问公有的 Base(double)，调用 Derived(5) 因无权访问私有构造报错
// ============================================================================
class Base {
	Base(int) {}
public:
	Base(double) {}
};

class Derived : public Base {
public:
	using Base::Base;
};

int main()
{
	Derived d(5.5);
	Derived d1(5);
}
