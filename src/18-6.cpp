// ============================================================================
// 【说明】：演示 C++17 switch 语句带初始化器（switch with initializer）的用法。
// 【重点】：
//   1. switch (std::unique_lock<std::mutex> lk(cv_m); cv.wait_for(lk, 100ms))
//   2. 将等待条件变量的 RAII 锁与分支状态枚举判断融合在一起
// ============================================================================
#include <condition_variable>
#include <chrono>
using namespace std::chrono_literals;

std::condition_variable cv;
std::mutex cv_m;

int main()
{
	switch (std::unique_lock<std::mutex> lk(cv_m); cv.wait_for(lk, 100ms))
	{
	case std::cv_status::timeout:
		break;
	case std::cv_status::no_timeout:
		break;
	}
}
