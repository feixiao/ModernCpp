# 现代 C++ 快速入门

本仓库收集了 275 个现代 C++ 示例文件，内容覆盖 C++11、C++14、C++17 和 C++20。示例按章节放在 [`src`](src) 目录中，适合围绕单个语言特性阅读、修改和验证。

参考资料：[《Modern C++ Tutorial: C++11/14/17/20》](https://github.com/changkun/modern-cpp-tutorial.git)

## 目录结构

```text
.
├── CMakeLists.txt       # 7 个早期示例的构建入口
├── ReadMe.md            # 项目说明和源码导航
└── src/
    ├── 1-1.cpp
    ├── 2-1.cpp
    ├── 2-2.cpp
    └── ...              # 共 42 章、275 个示例
```

`src/<章节>-<序号>.cpp` 是统一命名规则。例如，`6-1.cpp` 到 `6-9.cpp` 都属于第 6 章，主题是移动语义和完美转发。同一章通常通过一组相近代码展示正确写法、错误写法及版本差异。

## 5 分钟熟悉 `src`

1. 从下方章节索引定位感兴趣的语言特性。
2. 先读该章的 `n-1.cpp`，识别 `main()`、核心类型和关键表达式。
3. 再按编号阅读同章文件；重点比较相邻示例发生了什么变化。
4. 单独编译并运行一个示例，不要直接假设整章都能批量构建。
5. 修改输入、类型或限定符，再观察编译结果和输出。

以下命令适合快速查看和比较一章代码：

```bash
# 列出第 6 章全部示例
printf '%s\n' src/6-*.cpp

# 查找第 41 章中的 Concepts 和约束表达式
rg -n 'concept|requires' src/41-*.cpp

# 比较两个相邻示例
diff -u src/21-1.cpp src/21-2.cpp
```

## 章节索引

| 章节 | 主要内容 | 建议入口 |
|---:|---|---|
| 1 | 整数类型边界与 `numeric_limits` | `src/1-1.cpp` |
| 2 | 命名空间、内联命名空间和嵌套命名空间 | `src/2-1.cpp` |
| 3 | `auto` 非类型模板参数 | `src/3-1.cpp` |
| 4 | `decltype(auto)` 与引用推导 | `src/4-1.cpp` |
| 5 | 尾置返回类型与返回类型推导 | `src/5-1.cpp` |
| 6 | 右值引用、移动语义和完美转发 | `src/6-1.cpp` |
| 7 | Lambda 表达式和捕获 | `src/7-1.cpp` |
| 8 | 非静态数据成员默认初始化 | `src/8-1.cpp` |
| 9 | 列表初始化与统一初始化语法 | `src/9-1.cpp` |
| 10 | `default`、`delete` 与平凡类型 | `src/10-1.cpp` |
| 11 | 联合体及非平凡成员的生命周期 | `src/11-1.cpp` |
| 12 | 委托构造函数与构造异常 | `src/12-1.cpp` |
| 13 | 继承构造函数和 `using` 声明 | `src/13-1.cpp` |
| 14 | 枚举、强类型枚举和底层类型 | `src/14-1.cpp` |
| 15 | 聚合类型与聚合初始化 | `src/15-1.cpp` |
| 16 | `override` 和 `final` | `src/16-1.cpp` |
| 17 | 范围 `for` 与自定义迭代 | `src/17-1.cpp` |
| 18 | `if`/`switch` 初始化语句 | `src/18-1.cpp` |
| 19 | `static_assert` 编译期断言 | `src/19-1.cpp` |
| 20 | 元组和结构化绑定 | `src/20-1.cpp` |
| 21 | `noexcept`、条件异常说明和类型规则 | `src/21-1.cpp` |
| 22 | 类型别名与别名模板 | `src/22-1.cpp` |
| 23 | `nullptr` 与空指针类型 | `src/23-1.cpp` |
| 24 | 三路比较运算符 `<=>` | `src/24-1.cpp` |
| 25 | `thread_local` 线程存储期 | `src/25-1.cpp` |
| 26 | 内联变量 | `src/26-1.cpp` |
| 27 | `constexpr`、`if constexpr` 和常量求值 | `src/27-1.cpp` |
| 28 | 成员函数链式调用 | `src/28-1.cpp` |
| 29 | 十六进制浮点、数字分隔符和用户定义字面量 | `src/29-1.cpp` |
| 30 | 对象布局、`alignas`/`alignof` 和对齐分配 | `src/30-1.cpp` |
| 31 | 标准属性：`noreturn`、`deprecated`、`nodiscard` 等 | `src/31-1.cpp` |
| 32 | `__has_include` 头文件能力检测 | `src/32-1.cpp` |
| 33 | 协程、`co_await`、`co_yield` 和早期 experimental 接口 | `src/33-1.cpp` |
| 34 | 初始化、`explicit`、复制消除和对象生命周期 | `src/34-1.cpp` |
| 35 | 可变参数模板、包展开和折叠表达式 | `src/35-1.cpp` |
| 36 | 模板模板参数 | `src/36-1.cpp` |
| 37 | 非类型模板参数、默认模板参数及相关规则 | `src/37-1.cpp` |
| 38 | 模板实参推导 | `src/38-1.cpp` |
| 39 | 用户定义推导指引 | `src/39-1.cpp` |
| 40 | SFINAE 与基于表达式的重载选择 | `src/40-1.cpp` |
| 41 | Concepts、`requires` 和约束 | `src/41-1.cpp` |
| 42 | 模板语法演进、变量模板及约束写法对照 | `src/42-1.cpp` |

## 编译和运行

### 使用 CMake 构建已配置示例

根目录的 `CMakeLists.txt` 使用 C++17，目前只配置了 7 个目标：

| 目标 | 源文件 |
|---|---|
| `ex01` | `src/1-1.cpp` |
| `ex02-01` | `src/2-1.cpp` |
| `ex02-02` | `src/2-2.cpp` |
| `ex03` | `src/3-1.cpp` |
| `ex04` | `src/4-1.cpp` |
| `ex06_05` | `src/6-5.cpp` |
| `ex06_08` | `src/6-8.cpp` |

必须使用独立构建目录；项目会拒绝在源码目录内构建：

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target ex01
./build/ex01
```

当前 CMake 配置只处理 Linux 和 macOS。

### 单独编译任意示例

学习 `src` 时，推荐直接编译单个文件。C++20 可以覆盖多数示例使用的语言特性：

```bash
mkdir -p build/single
c++ -std=c++20 -Wall -Wextra src/29-2.cpp -o build/single/29-2
./build/single/29-2
```

涉及线程的示例通常还需要 `-pthread`：

```bash
c++ -std=c++20 -pthread src/25-3.cpp -o build/single/25-3
./build/single/25-3
```

## 阅读时的注意事项

- 一些示例故意展示编译失败，例如错误的 `override`、失败的 `static_assert` 或不满足 Concepts 的类型。源码注释通常会标出“编译失败”或“编译错误”。
- 一些文件是代码片段，不包含完整的头文件或 `main()`；它们用于解释语法，不是独立程序。
- 少数示例依赖编译器扩展、平台相关汇编或早期 `<experimental/...>` 头文件，现代编译器不一定继续提供对应接口。
- 部分文件在注释中保留了汇编或 GIMPLE 输出，用于观察语言特性对生成代码的影响。
- 遇到失败时，先判断它是教学反例、标准版本差异，还是平台/编译器扩展差异，再决定是否修改代码。

## 推荐阅读路线

- 基础语法迁移：1 → 2 → 3 → 4 → 5 → 7 → 9 → 17 → 18 → 20。
- 对象模型与性能：6 → 8 → 10 → 11 → 12 → 13 → 15 → 30 → 34。
- 泛型编程：19 → 22 → 27 → 35 → 36 → 37 → 38 → 39 → 40 → 41 → 42。
- C++20 重点：24 → 27 → 31 → 33 → 37 → 41 → 42。