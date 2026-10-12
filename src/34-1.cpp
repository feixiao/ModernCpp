// ============================================================================
// 【说明】：演示没有 explicit 的自定义类型转换函数 operator bool() 引发的隐式误判 Bug。
// 【重点】：
//   1. 隐式布尔转换允许容器对象直接隐式转为整数参与数学运算
//   2. 引出 34-4 中 explicit operator bool() 解决安全隐患
// ============================================================================
#include <iostream>
#include <vector>

template<class T>
class SomeStorage {
public:
	SomeStorage() = default;
	SomeStorage(std::initializer_list<T> l) : data_(l) {};
	operator bool() const { return !data_.empty(); }
private:
	std::vector<T> data_;
};

int main()
{
	SomeStorage<float> s1{ 1., 2., 3. };
	SomeStorage<int> s2{ 1, 2, 3 };

	std::cout << std::boolalpha;
	std::cout << "s1 == s2 : " << (s1 == s2) << std::endl;
	std::cout << "s1 + s2  : " << (s1 + s2) << std::endl;
}
