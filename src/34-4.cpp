// ============================================================================
// 【说明】：演示 C++11 explicit operator bool() 显式类型转换运算符。
// 【重点】：
//   1. explicit operator bool() const;
//   2. 仅允许在显式布尔上下文（如 if (s)、while (s) 等条件语句中）执行语境转换，禁止直接转为 int 运算
// ============================================================================
#include <iostream>
#include <vector>

template<class T>
class SomeStorage {
public:
	SomeStorage() = default;
	SomeStorage(std::initializer_list<T> l) : data_(l) {};
	explicit operator bool() const { return !data_.empty(); }
private:
	std::vector<T> data_;
};

int main()
{
	SomeStorage<float> s1{ 1., 2., 3. };
	SomeStorage<int> s2{ 1, 2, 3 };

	std::cout << std::boolalpha;
	std::cout << "s1 == s2 : " << (s1 == s2) << std::endl;	// 编译失败
	std::cout << "s1 + s2  : " << (s1 + s2) << std::endl;	// 编译失败
	std::cout << "s1 : " << static_cast<bool>(s1) << std::endl;
	std::cout << "s2 : " << static_cast<bool>(s2) << std::endl;
	if (s1) {
		std::cout << "s1 is not empty" << std::endl;
	}
}
