// ============================================================================
// 【说明】：通过编译器中间表示（GCC GIMPLE IR）深入剖析 Lambda 闭包类的底层生成细节。
// 【重点】：
//   1. 源码包含详细 GIMPLE 分析输出
//   2. 证实 [=] 会生成 struct __lambda0 结构体并在构造时拷贝赋值成员 __x, __y
//   3. operator() 实质上是隐式接收 const __closure* 参数的成员函数
// ============================================================================
#include <iostream>

int main()
{
    int x = 5, y = 8;
    auto foo = [=] { return x * y; };
    int z = foo();
}

/* GIMPLE

main ()
{
  int D.39253;
  {
    int x;
    int y;
    struct __lambda0 foo;
    typedef struct __lambda0 __lambda0;
    int z;

    try
      {
        x = 5;
        y = 8;
        foo.__x = x;
        foo.__y = y;
        z = main()::<lambda()>::operator() (&foo);
      }
    finally
      {
        foo = {CLOBBER};
      }
  }
  D.39253 = 0;
  return D.39253;
}


main()::<lambda()>::operator() (const struct __lambda0 * const __closure)
{
  int D.39255;
  const int x [value-expr: __closure->__x];
  const int y [value-expr: __closure->__y];

  _1 = __closure->__x;
  _2 = __closure->__y;
  D.39255 = _1 * _2;
  return D.39255;
}


*/