// ============================================================================
// 【说明】：演示 C++11 新增的长整型类型 long long 与 unsigned long long 的数值范围获取方式。
// 【重点】：
//   1. 传统的 C 宏方法：LLONG_MAX, LLONG_MIN, ULLONG_MAX
//   2. C++ 推荐方式：std::numeric_limits<long long>::max()/min() 类模板方法
//   3. 使用 printf 格式化输出长整型占位符（%lld 和 %llu）
// ============================================================================
#include <iostream>
#include <limits>
#include <cstdio>
int main(int argc, char *argv[])
{
	// 使用宏方法
	std::cout << "LLONG_MAX = " << LLONG_MAX << std::endl;
	std::cout << "LLONG_MIN = " << LLONG_MIN << std::endl;
	std::cout << "ULLONG_MAX = " << ULLONG_MAX << std::endl;
	
	// [推荐做法] 使用类模板方法
	std::cout << "std::numeric_limits<long long>::max() = " 
		<< std::numeric_limits<long long>::max() << std::endl;
	std::cout << "std::numeric_limits<long long>::min() = " 
		<< std::numeric_limits<long long>::min() << std::endl;
	std::cout << "std::numeric_limits<unsigned long long>::max() = " 
		<< std::numeric_limits<unsigned long long>::max() << std::endl;
	
	// 使用printf打印输出
	std::printf("LLONG_MAX = %lld\n", LLONG_MAX);	
	std::printf("LLONG_MIN = %lld\n", LLONG_MIN);
	std::printf("ULLONG_MAX = %llu\n", ULLONG_MAX);
}
