#include <iostream>
#include <string>

class Count {
public:
	int Get() { return count_++; }
	int count_ = 0;
};

class MyStringWithIndex : 
	public std::string, 
	public Count {
public:
	int index_ = 0;
};

std::ostream& operator << (std::ostream &o, MyStringWithIndex& s)
{
	o << s.index_ << ":" << s.Get() << ":" << s.c_str();
	return o;
}

int main()
{
	MyStringWithIndex s{ "hello world", 7, 11 };
	std::cout << s << std::endl;
	std::cout << s << std::endl;
}
