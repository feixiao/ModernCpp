// ============================================================================
// 【说明】：通过 GIMPLE 中间代码分析普通虚函数在运行时的虚表查找（vtable lookup）机制。
// 【重点】：
//   1. 普通虚函数调用必须经过 _vptr.X 虚表间接寻址
//   2. 作为 27-15 constexpr 虚函数的性能对比背景
// ============================================================================
struct X
{
    virtual int f() const { return 1; }
};

 int main() {
    X x;
    int i = x.f();
 }

/* GIMPLE

main ()
{
  int D.2137;

  {
    struct X x;
    int i;

    try
      {
        _1 = &_ZTV1X + 16;
        x._vptr.X = _1;
        i = X::f (&x); // 注意此处赋值
      }
    finally
      {
        x = {CLOBBER};
      }
  }
  D.2137 = 0;
  return D.2137;
}


X::f (const struct X * const this)
{
  int D.2139;

  D.2139 = 1;
  return D.2139;
}

*/