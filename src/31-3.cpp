// ============================================================================
// 【说明】：演示 C++11 标准属性 [[noreturn]] 的使用与优化效果。
// 【重点】：
//   1. [[noreturn]] void foo() 告知编译器该函数绝不会正常返回调用者（如抛出异常或退出进程）
//   2. 编译器据此省去函数末尾的返回清理代码，并在调用点后抑制不可达代码警告
// ============================================================================
[[noreturn]] void foo() {}
void bar() {}

int main()
{
    foo();
    bar();
}

/*

foo():
.LFB0:
        push    rbp
        mov     rbp, rsp
        nop
        pop     rbp
        ret
.LFE0:
bar():
.LFB1:
        push    rbp
        mov     rbp, rsp
        nop
        pop     rbp
        ret
.LFE1:
main:
.LFB2:
        push    rbp
        mov     rbp, rsp
        call    foo()
.LFE2:

*/