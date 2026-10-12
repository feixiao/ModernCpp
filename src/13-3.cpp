// ============================================================================
// 【说明】：演示 C++11 继承构造函数（Inheriting Constructors）的基本语法。
// 【重点】：
//   1. using Base::Base; 一行代码继承基类所有的非默认构造函数
//   2. 派生类无需再重复书写与基类参数一致的转发构造函数列表
// ============================================================================
class Base {
public:
	Base() : x_(0), y_(0.) {};
	Base(int x, double y) : x_(x), y_(y) {}
	Base(int x) : x_(x), y_(0.) {}
	Base(double y) : x_(0), y_(y) {}
private:
	int x_;
	double y_;
};


class Derived : public Base {
public:
	using Base::Base;
};
