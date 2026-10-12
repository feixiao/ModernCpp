// ============================================================================
// 【说明】：演示多继承体系下使用继承构造函数引发二义性冲突的场景（编译错误）。
// 【重点】：
//   1. Base1 和 Base2 都拥有签名相同的构造函数 (int)
//   2. 派生类同时 using Base1::Base1 与 using Base2::Base2 时，实例化 Derived(5) 产生二义性报错
// ============================================================================
class Base1 {
public:
	Base1(int) { std::cout << "Base1(int x)" << std::endl; };
};

class Base2 {
public:
	Base2(int) { std::cout << "Base2(int x)" << std::endl; };
};

class Derived : public Base1, Base2 {
public:
	using Base1::Base1;
	using Base2::Base2;
};

int main()
{
	Derived d(5);
}
