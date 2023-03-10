#include <iostream>
#include <type_traits>
template<class T> auto minus(T a, T b)
{
	if constexpr (std::is_same<T, double>::value) {
		if (std::abs(a - b) < 0.0001) {
			return 0.;
		}
		else {
			return a - b;
		}
	}
	else {
		return static_cast<int>(a - b);
	}
}

int main()
{
	std::cout << minus(5.6, 5.11) << std::endl;
	std::cout << minus(5.60002, 5.600011) << std::endl;
	std::cout << minus(6, 5) << std::endl;
}
