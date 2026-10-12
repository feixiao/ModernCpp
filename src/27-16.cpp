// ============================================================================
// 【说明】：演示 C++20 constexpr 虚函数在多态继承体系和成员函数指针下的编译期静态断言验证。
// 【重点】：
//   1. 覆盖多级虚继承 X1 -> X2 -> X3 -> X4 中纯虚与重写 constexpr 虚函数
//   2. static_assert 验证通过基类引用与函数指针 (r2.*pf)() 在编译期解析出正确定位
// ============================================================================
struct X1
{
    virtual int f() const = 0;
};

struct X2: public X1
{
    constexpr virtual int f() const { return 2; }
};

struct X3: public X2
{
    virtual int f() const { return 3; }
};

struct X4: public X3
{
    constexpr virtual int f() const { return 4; }
};

constexpr int (X1::*pf)() const = &X1::f;

constexpr X2 x2;
static_assert( x2.f() == 2 );
static_assert( (x2.*pf)() == 2 );

constexpr X1 const& r2 = x2;
static_assert( r2.f() == 2 );
static_assert( (r2.*pf)() == 2 );

constexpr X1 const* p2 = &x2;
static_assert( p2->f() == 2 );
static_assert( (p2->*pf)() == 2 );

constexpr X4 x4;
static_assert( x4.f() == 4 );
static_assert( (x4.*pf)() == 4 );

constexpr X1 const& r4 = x4;
static_assert( r4.f() == 4 );
static_assert( (r4.*pf)() == 4 );

constexpr X1 const* p4 = &x4;
static_assert( p4->f() == 4 );
static_assert( (p4->*pf)() == 4 );
