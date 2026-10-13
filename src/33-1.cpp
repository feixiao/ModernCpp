// ============================================================================
// 【说明】：演示 C++20 协程（Coroutines）中的 co_return 关键字与异步等待概念。
// 【重点】：
//   1. 协程函数体内包含 co_return 5;
//   2. 返回 std::future 或自定义 promise 机制管理异步挂起和恢复
// ============================================================================
#include <iostream>
#include <chrono>
#include <future>

// 使用 std::future 演示协程的异步返回与等待机制
using namespace std::chrono_literals;

std::future<int> foo()
{
	std::cout << "call foo\n";
    std::this_thread::sleep_for(3s);
    co_return 5;
}

std::future<std::future<int>> bar()
{
	std::cout << "call bar\n";
	std::cout << "before foo\n";
	// 调用 foo 协程并等待其完成，获取返回值
	auto n = co_await std::async(foo);	// 挂起点
	std::cout << "after foo\n";
	co_return n;
}

int main()
{
	std::cout << "before bar\n";
	auto i = bar();
	std::cout << "after bar\n";
    i.wait();
	std::cout << "result = " << i.get().get();
}
