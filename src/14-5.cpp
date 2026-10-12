// ============================================================================
// 【说明】：演示 C++11 强类型/作用域枚举（scoped enum: enum class）的核心特性。
// 【重点】：
//   1. enum class HighSchool 成员必须通过作用域限定访问（HighSchool::student）
//   2. 消除全局命名冲突，且禁止不同枚举类型之间或枚举与 int 之间的隐式比较和转换
// ============================================================================
#include <iostream>

enum class HighSchool {
    student,
    teacher,
    principal
};

enum class University {
    student,
    professor,
    principal
};

int main()
{
    HighSchool x = HighSchool::student;
    University y = University::student;
    bool b = x < HighSchool::headmaster;
    std::cout << std::boolalpha << b << std::endl;
}
