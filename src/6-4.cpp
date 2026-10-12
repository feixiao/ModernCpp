// ============================================================================
// 【说明】：演示大内存池（BigMemoryPool）在仅支持深拷贝时的昂贵性能瓶颈。
// 【重点】：
//   1. 每次函数返回与参数传递都触发深拷贝（memcpy 4096 字节）
//   2. 配合 6-5.cpp 形成鲜明对比，量化说明移动语义带来的巨大性能提升
// ============================================================================
#include <iostream>
class BigMemoryPool {
public:
	static const int PoolSize = 4096;
	BigMemoryPool() : pool_(new char[PoolSize]) {}
	~BigMemoryPool()
	{
		if (pool_ != nullptr) {
			delete[] pool_;
		}
	}

	BigMemoryPool(const BigMemoryPool& other) : pool_(new char[PoolSize])
	{
		std::cout << "copy big memory pool." << std::endl;
		memcpy(pool_, other.pool_, PoolSize);
	}

private:

	char *pool_;
};


BigMemoryPool get_pool(const BigMemoryPool& pool)
{
	return pool;
}

BigMemoryPool make_pool()
{
	BigMemoryPool pool;
	return get_pool(pool);
}

int main()
{
	BigMemoryPool my_pool = make_pool();
}
