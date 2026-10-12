// ============================================================================
// 【说明】：演示 C++11 类非静态数据成员的类内默认初始化（In-class Member Initializer）。
// 【重点】：
//   1. 传统 C++98 必须在每个构造函数的初始化列表中重复写 a_(0), b_(0.), c_("hello world")
//   2. C++11 支持在成员声明处直接赋默认值：int a_ = 0; std::string c_{"hello world"};
//   3. 避免多个重载构造函数中冗余的初始化代码，提升可维护性
// ============================================================================
class X {
public:
	X() : a_(0), b_(0.), c_("hello world") {}
	X(int a) : a_(a), b_(0.), c_("hello world") {}
	X(double b) : a_(0), b_(b), c_("hello world") {}
	X(const std::string &c) : a_(0), b_(0.), c_(c) {}

private:
	int a_;
	double b_;
	std::string c_;
};

/*

class X {
public:
	X() {}
	X(int a) : a_(a) {}
	X(double b) : b_(b) {}
	X(const std::string &c) : c_(c) {}

private:
	int a_ = 0;
	double b_{ 0. };
	std::string c_{ "hello world" };
};

*/