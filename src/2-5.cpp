// ============================================================================
// 【说明】：演示 C++20 嵌套命名空间与内联命名空间的紧凑简化定义语法。
// 【重点】：
//   1. C++20 支持 namespace A::B::inline C 或 namespace A::inline B::C 这种内联紧凑写法
//   2. 等同于传统 C++ 中多层嵌套展开并定义 inline namespace 的冗长写法
// ============================================================================
namespace A::B::inline C {
    int foo() { return 5; }
}
// 或者
namespace A::inline B::C {
    int foo() { return 5; }
}

// 等同于：

namespace A::B { 
    inline namespace C {
        int foo() { return 5; }
    } 
}

namespace A { 
    inline namespace B { 
        namespace C {
            int foo() { return 5; }
        } 
    } 
}
