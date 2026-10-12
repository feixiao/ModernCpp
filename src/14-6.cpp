// ============================================================================
// 【说明】：演示 C++11 为 enum class 显式指定底层类型（Underlying Type）的语法。
// 【重点】：
//   1. enum class E : unsigned int 明确底层存储为无符号整型
//   2. 解决枚举大小平台不确定性与跨平台二进制接口（ABI）稳定性问题
// ============================================================================
enum class E : unsigned int {
    e1 = 1,
    e2 = 2,
    e3 = 0xfffffff0
};

int main()
{
    bool b = e1 < e3;
    std::cout << std::boolalpha << b << std::endl;
}
