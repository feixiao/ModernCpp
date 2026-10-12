// ============================================================================
// 【说明】：演示 C++20 协程等待体（Awaitable）的三个核心接口约定：ready, suspend, resume。
// 【重点】：
//   1. await_ready()：判断操作是否已完成、是否需要挂起
//   2. await_suspend(handle)：协程挂起时的回调句柄保存
//   3. await_resume()：协程恢复时返回最终结果数据
// ============================================================================
class awaitable_string : public std::string {
public:
	using std::string::string;
	bool await_ready() const { return true; }
	void await_suspend(std::experimental::coroutine_handle<> h) const {}
	std::string await_resume() const { return *this; }
};

/*

class awaitable_string : public std::string {
public:
	using std::string::string;
	bool await_ready() const { return false; }
	void await_suspend(std::experimental::coroutine_handle<> h) const {
		std::thread t{ [h] {
            // 模拟复杂操作，用时3秒
			std::this_thread::sleep_for(3s);
			h(); }
		};
		t.detach();
	}
	std::string await_resume() const { return *this; }
};


*/

std::future<std::string> foo()
{
	auto str = co_await awaitable_string{ "hello" };
	co_return str;
}

int main()
{
	auto s = foo();
	std::cout << s.get();
}
