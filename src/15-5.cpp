// ============================================================================
// 【说明】：演示受保护的非默认构造函数对派生类聚合属性的影响。
// 【重点】：
//   1. 基类 BaseData 构造函数为 protected，派生类聚合初始化的访问权限控制
// ============================================================================
#include <iostream>
#include <string>

class BaseData {
	int data_;
public:
	int Get() { return data_; }
protected:
	BaseData() : data_(11) {}
};

class DerivedData : public BaseData {
public:
};

int main()
{
	DerivedData d{};
	std::cout << d.Get() << std::endl;
}
