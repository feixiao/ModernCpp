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
    std::cout << *std::find_if(x.cbegin(), 
                             x.cend(), 
                             [](int i) { return (i % 3) == 0; }) << std::endl;
}
