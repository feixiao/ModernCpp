// ============================================================================
// 【说明】：演示派生类中自定义构造函数对继承构造函数的就近覆盖规则。
// 【重点】：
//   1. 派生类声明 using Base::Base 继承了 Base(int) 和 Base(double)
//   2. 但派生类显式手写了 Derived(int)，则派生类版本优先生效，覆盖从基类继承的同签名版本
// ============================================================================
class Base {
public:
	Base() : x_(0), y_(0.) {};
	Base(int x, double y) : x_(x), y_(y) {}
	Base(int x) : x_(x), y_(0.) { std::cout << "Base(int x)" << std::endl; }
	Base(double y) : x_(0), y_(y) { std::cout << "Base(double y)" << std::endl; }
private:
	int x_;
	double y_;
};

class Derived : public Base {
public:
	using Base::Base;
	Derived(int x) { std::cout << "Derived(int x)" << std::endl; }
};

int main()
{
	Derived d(5);
	Derived d1(5.5);
}
