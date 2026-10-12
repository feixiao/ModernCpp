// ============================================================================
// 【说明】：演示利用 enum class 实现强类型标识符（Strong Type ID / 强类型别名）的模式。
// 【重点】：
//   1. enum class Index : int {}; 防止索引与普通整数或其他业务 ID 发生混淆
//   2. 同一强类型枚举对象支持同类型关系比较（a < b）
// ============================================================================
#include <iostream>
enum class Index : int {};

int main()
{
	Index a{ 5 };
	Index b{ 10 };
	// a = 12;
	// int c = b;
	std::cout << "a < b is " 
		<< std::boolalpha 
		<< (a < b) << std::endl;
}
