#include <cstdio>


namespace S1 {
	void foo() {
		printf("%s\n", __FUNCTION__);
	}
}

namespace S2 {
	void foo() {
		printf("%s\n", __FUNCTION__);
	}
}

using namespace S1;

int main()
{
	foo();
	S2::foo();
}
