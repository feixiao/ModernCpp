// ============================================================================
// 【说明】：演示嵌套类模板中的双重形参包配对组装（类似 zip 打包操作）。
// 【重点】：
//   1. Tuple<Pair<Args1, Args2>...> 将外层与内层两个形参包一一配对组合
//   2. 两个包长度不匹配时触发编译错误
// ============================================================================
template<class...> struct Tuple {};
template<class T1, class T2> struct Pair {};
template<class ...Args1>
struct zip {
	template<class ...Args2>
	struct with {
		typedef Tuple<Pair<Args1, Args2>...> type;
	};
};

int main()
{
	zip<short, int>::with<unsigned short, unsigned>::type t1;	// 编译成功
	zip<short>::with<unsigned short, unsigned>::type t2;			// 编译失败，形参包长度不同
}
