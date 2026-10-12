// ============================================================================
// 【说明】：演示 C++98 传统不限范围枚举（unscoped enum）的全局命名污染与隐式整型转换隐患。
// 【重点】：
//   1. 枚举成员作用域泄漏到全局（不同枚举不能有同名成员）
//   2. 枚举值隐式转换为 int，导致两个毫不相干的枚举（School 与 Company）可以互相比较大小
// ============================================================================
enum School {
  principal,
  teacher,
  student
};

enum Company {
  chairman,
  manager,
  employee
};

int main()
{
  School x = student;
  Company y = manager;
  bool b = student >= manager;	// 不同类型之间的比较操作
  b = x < employee;
  int y = student;				// 隐式转换为int
}
