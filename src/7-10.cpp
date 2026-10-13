// ============================================================================
// 【说明】：演示现代 C++ 中将 Lambda 作为谓词（Predicate）传递给 STL 标准算法。
// 【重点】：
//   1. 结合 std::find_if 查找容器中第一个能被 3 整除的元素
//   2. 代替传统手写命名函数或复杂仿函数，提升代码局部性与简洁度
// ============================================================================
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> x = {1, 2, 3, 4, 5};
    // 使用 Lambda 作为谓词传递给 std::find_if
    // Lambda 表达式捕获列表为空，按值传递参数 i，返回是否能被 3 整除
    // std::find_if 会遍历容器 x，依次将元素传递给 Lambda，直到找到第一个返回 true 的元素
    // 调用 std::find_if 并输出结果，找到的第一个能被 3 整除的元素是 3
    // 这里直接将 Lambda 作为参数传递给 std::find_if，无需单独定义变量
    std::cout << *std::find_if(x.cbegin(), 
                             x.cend(), 
                             [](int i) { return (i % 3) == 0; }) << std::endl;
}
