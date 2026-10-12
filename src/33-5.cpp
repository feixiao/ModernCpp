// ============================================================================
// 【说明】：演示通过重载 operator co_await 定制特定类型的等待体转换。
// 【重点】：
//   1. awaitable_string operator co_await(std::string&& str)
//   2. 使得普通字符串类型可以直接参与 co_await 表达式执行挂起与恢复
// ============================================================================
awaitable_string operator co_await(std::string&& str)
{
	return awaitable_string{ str };
}

std::future<std::string> foo()
{
	auto str = co_await std::string{ "hello" };
	co_return str;
}
