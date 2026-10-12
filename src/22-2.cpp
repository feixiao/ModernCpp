// ============================================================================
// 【说明】：演示 C++98 传统通过外层类模板包装 typedef 模拟别名模板的繁琐方案。
// 【重点】：
//   1. struct int_map { typedef std::map<int, T> type; };
//   2. 使用时必须繁琐地书写 int_map<std::string>::type，作为 22-1 的对比参考
// ============================================================================
#include <map>
#include <string>

template<class T>
struct int_map {
	typedef std::map<int, T> type;
};

int main()
{
	int_map<std::string>::type int2string;
	int2string[11] = "7";
}
