// ============================================================================
// 【说明】：演示 C++17 强制复制消除使不可拷贝不可移动类型（如 std::atomic）可按值从工厂函数返回。
// 【重点】：
//   1. std::atomic 既没有拷贝构造也没有移动构造
//   2. 依赖 C++17 强制复制消除，工厂函数 create<std::atomic<int>>(11) 可以直接就地初始化变量
// ============================================================================
#include <atomic>

template<class T, class Arg>
T create(Arg&& arg)
{
	return T(std::forward<Arg>(arg));
}

int main()
{
	std::atomic<int> x = create<std::atomic<int>>(11);
}
