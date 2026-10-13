// ============================================================================
// 【说明】：对比 Lambda 默认只读常量性、引用捕获与 mutable 说明符对捕获变量修改的区别。
// 【重点】：
//   1. bar1：值捕获生成的 operator() 默认是 const 成员函数，修改 x, y 会编译失败
//   2. bar2：[&x, &y] 引用捕获，可直接修改外部原变量
//   3. bar3：[x, y] () mutable 移除 operator() 的 const 属性，允许修改内部捕获副本（不影响外部）
// ============================================================================
void bar1()
{
    int x = 5, y = 8;
    // 按值捕获 x 和 y，默认生成的 operator() 是 const 成员函数，无法修改捕获的变量
    auto foo = [x, y] {
        x += 1;             // 编译失败，无法改变捕获变量的值
        y += 2;             // 编译失败，无法改变捕获变量的值
        return x * y;
    };
    std::cout << foo() << std::endl;
}

void bar2()
{
    int x = 5, y = 8;

    // 按引用捕获 x 和 y，生成的 operator() 可以修改外部原变量
    auto foo = [&x, &y] {
        x += 1;
        y += 2;
        return x * y;
    };
    std::cout << foo() << std::endl;
}

void bar3()
{
    int x = 5, y = 8;
    // 按值捕获 x 和 y，并使用 mutable 移除 operator() 的 const 属性，允许修改内部捕获副本（不影响外部）
    auto foo = [x, y] () mutable {
        x += 1;
        y += 2;
        return x * y;
    };
    std::cout << foo() << std::endl;
}
