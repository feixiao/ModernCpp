// ============================================================================
// 【说明】：演示传统 C++11 std::packaged_task 与 future 异步执行模式（协程前奏）。
// 【重点】：
//   1. 传统异步任务调度依赖线程、packaged_task 与阻塞等待 get_future()
//   2. 作为对比说明无栈协程（Stackless Coroutine）在上下文切换与调度上的轻量优势
// ============================================================================
#include <iostream>
#include <chrono>
#include <future>
using namespace std::chrono_literals;

std::packaged_task<int()> task(
	[]() {
		std::cout << "call task\n";
		std::this_thread::sleep_for(3s); 
		return 5; 
	}
);

std::future<int> bar()
{
	return task.get_future();
}

/*
std::future<int> bar()
{
	std::future<int> r = task.get_future();
	std::thread t(std::move(task));
	t.detach();
	return r;
}
*/

std::future<void> foo()
{
	std::cout << "call foo\n";
	std::cout << "before bar\n";
	auto i = co_await bar();
	std::cout << "after bar\n";
	std::cout << "result = " << i;
}

int main()
{
	std::cout << "before foo\n";
	auto w = foo();
	std::cout << "after foo\n";
	w.wait();
}
