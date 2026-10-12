// ============================================================================
// 【说明】：演示 C++11 std::hexfloat 流操作符格式化输出浮点数的十六进制科学计数法表示。
// 【重点】：
//   1. std::hexfloat 能够以精准不失真的二进制底层形式打印浮点数（如 0x1.7p+2）
//   2. 配合 std::defaultfloat 恢复标准十进制浮点格式
// ============================================================================
#include <iostream>

int main()
{
	double float_array[]{ 5.875, 1000, 0.117 };
	for (auto elem : float_array) {
		std::cout << std::hexfloat << elem 
			<< " = " << std::defaultfloat << elem << std::endl;
	}
}
