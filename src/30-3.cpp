// ============================================================================
// 【说明】：演示内存对齐对 CPU 汇编级数据复制指令吞吐效率的显著性能影响。
// 【重点】：
//   1. 使用 x86 内嵌汇编 rep movsb 复制大块内存
//   2. 对比未对齐内存与 32 字节对齐内存复制耗时，体现高性能计算中内存对齐的重要性
// ============================================================================
#include <iostream>
#include <memory>
#include <chrono>
static inline void *__movsb(void *d, const void *s, size_t n) {
  asm volatile ("rep movsb"
                : "=D" (d),
                  "=S" (s),
                  "=c" (n)
                : "0" (d),
                  "1" (s),
                  "2" (n)
                : "memory");
  return d;
}

int main(int argc, char *argv[])
{
	constexpr int align_size = 32;
	constexpr int alloc_size = 10001;
	constexpr int buff_size = align_size + alloc_size;
	char dest[buff_size]{0};
	char src[buff_size]{0};
	void *dest_ori_ptr = dest;
	void *src_ori_ptr = src;
	size_t dest_size = sizeof(dest);
	size_t src_size = sizeof(src);
	char *dest_ptr = static_cast<char *>(std::align(align_size, alloc_size, dest_ori_ptr, dest_size));
	char *src_ptr = static_cast<char *>(std::align(align_size, alloc_size, src_ori_ptr, src_size));

	if (argc == 2 && argv[1][0] == '1') {
		++dest_ptr;
		++src_ptr;
	} 
	
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10000000; i++) {
		__movsb(dest_ptr, src_ptr, alloc_size - 1);
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "elapsed time = " << diff.count();
}
