// ============================================================================
// 【说明】：演示基于表达式有效性（Expression SFINAE）与 decltype 结合的重载决议。
// 【重点】：
//   1. auto foo(T t1, T t2) -> decltype(t1 + t2)
//   2. 两个 X 对象没有重载 operator+，表达式无效触发 SFINAE 剔除，自动选用普通非模板 foo(Y, Y)
// ============================================================================
struct X {};
struct Y { Y(X) {} }; // X 可以转化为 Y

X foo(Y, Y) { return X(); }

template <class T>
auto foo(T t1, T t2) -> decltype(t1 + t2) {
	return t1 + t2;
}

int main()
{
	X x1, x2;
	X x3 = foo(x1, x2);
}
