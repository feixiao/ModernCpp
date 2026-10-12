// ============================================================================
// 【说明】：演示自定义容器类实现 begin()、end() 与迭代器以支持基于范围的 for 循环。
// 【重点】：
//   1. 实现自定义迭代器类 IntIter（重载 !=, ++, *）
//   2. 容器类 FixIntVector 提供 begin() 与 end() 成员函数，接入 range-for 生态
// ============================================================================
#include <iostream>

class IntIter {
public:
	IntIter(int *p) : p_(p) {}
	bool operator!=(const IntIter& other)
	{
		return (p_ != other.p_);
	}

	const IntIter& operator++()
	{
		p_++;
		return *this;
	}

	int operator*() const
	{
		return *p_;
	}
private:
	int *p_;
};

template<unsigned int fix_size>
class FixIntVector {
public:
	FixIntVector(std::initializer_list<int> init_list)
	{
		int *cur = data_;
		for (auto e : init_list) {
			*cur = e;
			cur++;
		}
	}

	IntIter begin()
	{
		return IntIter(data_);
	}

	IntIter end()
	{
		return IntIter(data_ + fix_size);
	}
private:
	int data_[fix_size]{0};
};

int main()
{
	FixIntVector<10> fix_int_vector {1, 3, 5, 7, 9};
	for (auto e : fix_int_vector)
	{
		std::cout << e << std::endl;
	}
}
