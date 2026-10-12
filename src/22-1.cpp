// ============================================================================
// 【说明】：演示 C++11 别名模板（Alias Template）通过 using 定义泛型类型别名。
// 【重点】：
//   1. template<class T> using int_map = std::map<int, T>;
//   2. 语法直观自然，无需像 C++98 一样借助于结构体内部嵌套 typedef 包装
// ============================================================================
#include <map>
#include <string>

template<class T>
using int_map = std::map<int, T>;

int main()
{
	int_map<std::string> int2string;
	int2string[11] = "7";
}
