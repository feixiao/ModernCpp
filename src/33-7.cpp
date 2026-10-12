// ============================================================================
// 【说明】：演示自定义协程承诺对象（promise_type）实现自定义整数生成器。
// 【重点】：
//   1. 协程返回类型 my_int_generator 内部嵌套定义 struct promise_type
//   2. 实现 get_return_object, initial_suspend, final_suspend, yield_value 等生命周期钩子
// ============================================================================
#include <experimental/resumable>
using namespace std::experimental;
struct my_int_generator {
	struct promise_type {
		int* value_ = nullptr;

		my_int_generator get_return_object() {
			return my_int_generator{ *this };
		}
		auto initial_suspend() const noexcept {
			return suspend_always{};
		}
		auto final_suspend() const noexcept {
			return suspend_always{};
		}
		auto yield_value(int& value) {
			value_ = &value;
			return suspend_always{};
		}
		void return_void() {}
	};

	explicit my_int_generator(promise_type& p) 
		: handle_(coroutine_handle<promise_type>::from_promise(p)) {}
	~my_int_generator() {
		if (handle_) {
			handle_.destroy();
		}
	}
	coroutine_handle<promise_type> handle_;
};

my_int_generator foo()
{
	for (int i = 0; i < 10; i++) {
		co_yield i;
	}
}

int main()
{
	auto obj = foo();
}
