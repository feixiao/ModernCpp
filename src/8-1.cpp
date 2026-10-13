// ============================================================================
// 【说明】：演示 C++11 类非静态数据成员的类内默认初始化（In-class Member Initializer）。
// 【重点】：
//   1. 传统 C++98 必须在每个构造函数的初始化列表中重复写 a_(0), b_(0.), c_("hello world")
//   2. C++11 支持在成员声明处直接赋默认值：int a_ = 0; std::string c_{"hello world"};
//   3. 避免多个重载构造函数中冗余的初始化代码，提升可维护性
// ============================================================================
class X {
public:
	// 构造函数中仍然可以使用初始化列表，但不再需要重复初始化默认值
	X() : a_(0), b_(0.), c_("hello world") {}
	// 如果没有提供参数，成员变量将使用类内默认初始化的值
	X(int a) : a_(a), b_(0.), c_("hello world") {}
	// 如果只提供 b 参数，其他成员变量将使用类内默认初始化的值
	X(double b) : a_(0), b_(b), c_("hello world") {}
	// 如果只提供 c 参数，其他成员变量将使用类内默认初始化的值
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