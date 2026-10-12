// ============================================================================
// 【说明】：演示 C++98 传统通过 const 整型与宏常量作为编译期常量的做法。
// 【重点】：
//   1. const int index0 = 0 作为 switch case 分支标签与模板参数
//   2. 属于编译期常量的早期形式，作为 C++11 constexpr 机制的对比背景
// ============================================================================
const int index0 = 0;
#define index1 1

// case语句
switch (argc)
{
case  index0:
    std::cout << "index0" << std::endl;
    break;
case index1:
    std::cout << "index1" << std::endl;
    break;
default:
    std::cout << "none" << std::endl;
}

const int x_size = 5 + 8;
#define y_size 6 + 7
// 数组长度
char buffer[x_size][y_size] = { 0 };

// 枚举成员
enum {
    enum_index0 = index0,
    enum_index1 = index1,
};

std::tuple<int, char> tp = std::make_tuple(4, '3');
// 非类型的模板参数
int x1 = std::get<index0>(tp);
char x2 = std::get<index1>(tp);
