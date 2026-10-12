// ============================================================================
// 【说明】：演示支持 co_return 传值的自定义协程承诺类型实现（return_value 接口）。
// 【重点】：
//   1. promise_type 中实现 return_value(int v) 捕获协程通过 co_return 产生的结果
//   2. 与 33-7 的 yield_value 互补，展示协程返回值的内部传递链路
// ============================================================================
struct my_int_return {
	struct promise_type {
		int value_ = 0;
		my_int_return get_return_object() {
			return my_int_return{ *this };
		}

		auto initial_suspend() const noexcept {
			return suspend_never{};
		}
		auto final_suspend() const noexcept {
			return suspend_always{};
		}
		
		void return_value(int value) {
			value_ = value;
		}
	};

	explicit my_int_return(promise_type& p)
		: handle_(coroutine_handle<promise_type>::from_promise(p)) {}

	~my_int_return() {
		if (handle_) {
			handle_.destroy();
		}
	}

	int get() {
		if (!ready_) {
			value_ = handle_.promise().value_;
			ready_ = true;
			if (handle_.done()) {
				handle_.destroy();
				handle_ = nullptr;
			}
		}
		
		return value_;
	}

	coroutine_handle<promise_type> handle_;
	int value_ = 0;
	bool ready_ = false;
};

my_int_return foo()
{
	co_return 5;
}

int main()
{
	auto obj = foo();
	std::cout << obj.get();
	std::cout << obj.get();
	std::cout << obj.get();
}
