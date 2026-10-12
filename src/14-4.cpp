// ============================================================================
// 【说明】：通过 GIMPLE 剖析编译期模板元编程利用 enum 存储计算常量（“enum hack”）。
// 【重点】：
//   1. C++98 中常用 enum { result = a + b } 充当编译期常量
//   2. GIMPLE 结果证明枚举常量在代码生成期被直接常量折叠为字面量（13）
// ============================================================================
#include <iostream>
template<int a, int b>
struct add {
    enum {
        result = a + b
    };
};

int main()
{
    std::cout << add<5, 8>::result << std::endl;
}

/* GIMPLE

main ()
{
  int D.39267;
  _1 = std::basic_ostream<char>::operator<< (&cout, 13);
  std::basic_ostream<char>::operator<< (_1, endl);
  D.39267 = 0;
  return D.39267;
}

*/