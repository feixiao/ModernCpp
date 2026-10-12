// ============================================================================
// 【说明】：演示 if 带初始化器结合 std::lock_guard 优雅管理锁作用域的经典工程模式。
// 【重点】：
//   1. if (std::lock_guard<std::mutex> lock(mx); shared_flag)
//   2. 仅在满足特定临界区条件时持有锁，离开 if 作用域自动析构解锁
// ============================================================================
#include <mutex>

std::mutex mx;
bool shared_flag = true;
int main()
{
	if (std::lock_guard<std::mutex> lock(mx); shared_flag) { 
		shared_flag = false;
	}
}
