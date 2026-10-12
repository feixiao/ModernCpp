// ============================================================================
// 【说明】：演示模板模板形参包（Template Template Parameter Pack）的声明与展开。
// 【重点】：
//   1. template<template<class ...> class ...Args> class bar : public Args<int, double>...
//   2. 支持接收任意数量的类模板作为参数并统一赋予具体类型特化继承
// ============================================================================
template<template<class ...> class ...Args>
class bar : public Args<int, double>... {
public:
	bar(const Args<int, double>& ...args) : Args<int, double>(args)... {}
};

template<class ...Args>
class baz1 {};

template<class ...Args>
class baz2 {};

int main()
{
	baz1<int, double> a1;
	baz2<int, double> a2;
	bar<baz1, baz2> b(a1, a2);
}
