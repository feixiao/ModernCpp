template <int N> constexpr bool Atomic = true;
template <int N> concept C = Atomic<N>;
template <int N> concept Add1 = C<N + 1>;
template <int N> concept AddOne = C<N + 1>;
template <int M> void f()
requires Add1<2 * M> {};
template <int M> void f()
requires AddOne<2 * M> && true {};

f<0>(); // 编译成功
