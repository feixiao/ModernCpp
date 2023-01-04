#include <chrono>
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

	BigMemoryPool(BigMemoryPool&& other)
	{
		std::cout << "move big memory pool." << std::endl;
		pool_ = other.pool_;
		other.pool_ = nullptr;
	}


	BigMemoryPool& operator=(BigMemoryPool&& other)
	{
		std::cout << "move(operator=) big memory pool." <<std::endl;
		if (pool_ != nullptr) {
			delete[] pool_;
		}
		pool_ = other.pool_;
		other.pool_ = nullptr;
		return *this;
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
	return std::move(pool);
}


BigMemoryPool make_pool()
{
	BigMemoryPool pool;
	return get_pool(pool);
}


int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	uint32_t count = 1;
	for (int i = 0; i < count; i++) {
		BigMemoryPool my_pool = make_pool();
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Time to call make_pool :" << diff.count() << " s" << std::endl;
}
