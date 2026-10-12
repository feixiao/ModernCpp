// ============================================================================
// 【说明】：演示 C++17 原生支持十六进制浮点数字面量（Hexadecimal Floating-Point Literals）。
// 【重点】：
//   1. 0x1.7p+2, 0x1.f4p+9, 0x1.df3b64p-4 直接在源码中作为浮点字面量参与运算
//   2. p 表示以 2 为底的指数幂，提供跨平台完全精确无舍入误差的浮点字面量定义
// ============================================================================
#include <iostream>

int main()
{
	double float_array[]{ 0x1.7p+2, 0x1.f4p+9, 0x1.df3b64p-4 };
	for (auto elem : float_array) {
		std::cout << std::hexfloat << elem 
			<< " = " << std::defaultfloat << elem << std::endl;
	}
}
