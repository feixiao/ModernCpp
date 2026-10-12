// ============================================================================
// 【说明】：演示类继承体系下数据成员分布对结构化绑定的约束规则。
// 【重点】：
//   1. 所有非静态数据成员必须全部位于同一个类中（不能基类有部分，派生类又有部分）
//   2. 若基类与派生类各定义了非静态成员，将破坏直接绑定规则引发编译报错
// ============================================================================
class BindBase1 {
public:
	int a = 42;
	double b = 11.7;
};

class BindTest1 : public BindBase1 {};

class BindBase2 {};

class BindTest2 : public BindBase2 {
public:
	int a = 42;
	double b = 11.7;
};

class BindBase3 {
public:
	int a = 42;
};

class BindTest3 : public BindBase3 {
public:
	double b = 11.7;
};

int main()
{
	BindTest1 bt1;
	BindTest2 bt2;
	BindTest3 bt3;
	auto[x1, y1] = bt1;	// 编译成功
	auto[x2, y2] = bt2;	// 编译成功
	auto[x3, y3] = bt3;	// 编译错误
}
