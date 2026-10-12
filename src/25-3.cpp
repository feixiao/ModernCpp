// ============================================================================
// 【说明】：多线程实战演示 thread_local 对象的按线程惰性构造与线程退出析构全过程。
// 【重点】：
//   1. 启动多个 std::thread，验证每个线程仅在首次执行对应函数时构造自己专属的 RefCount 对象
//   2. 打印线程 ID 证实不同线程彼此独立，线程终止时各自独立调用析构函数
// ============================================================================
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

std::mutex g_out_lock;

struct RefCount {
	RefCount(const char* f) : i(0), func(f) {
		std::lock_guard<std::mutex> lock(g_out_lock);
		std::cout << std::this_thread::get_id()
			<< "|" << func
			<< " : ctor i(" << i << ")" << std::endl;
	}

	~RefCount() {
		std::lock_guard<std::mutex> lock(g_out_lock);
		std::cout << std::this_thread::get_id()
			<< "|" << func
			<< " : dtor i(" << i << ")" << std::endl;
	}

	void inc()
	{
		std::lock_guard<std::mutex> lock(g_out_lock);
		std::cout << std::this_thread::get_id()
			<< "|" << func
			<< " : ref count add 1 to i(" << i << ")" << std::endl;
		i++;
	}

	int i;
	std::string func;
};
RefCount *lp_ptr = nullptr;

void foo(const char* f)
{
	std::string func(f);
	thread_local RefCount tv(func.append("#foo").c_str());
	tv.inc();
}

void bar(const char* f)
{
	std::string func(f);
	thread_local RefCount tv(func.append("#bar").c_str());
	tv.inc();
}

void threadfunc1()
{
	const char* func = "threadfunc1";
	foo(func);
	foo(func);
	foo(func);
}

void threadfunc2()
{
	const char* func = "threadfunc2";
	foo(func);
	foo(func);
	foo(func);
}

void threadfunc3()
{
	const char* func = "threadfunc3";
	foo(func);
	bar(func);
	bar(func);
}

int main()
{
	std::thread t1(threadfunc1);
	std::thread t2(threadfunc2);
	std::thread t3(threadfunc3);
	
	t1.join();
	t2.join();
	t3.join();
}
