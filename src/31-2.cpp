// ============================================================================
// 【说明】：通过汇编对比普通无返回值函数的返回控制流指令。
// 【重点】：
//   1. 普通 void 函数末尾生成 nop 与 ret 正常返回指令
//   2. 作为 31-3 中 [[noreturn]] 属性消除返回指令的对比参照
// ============================================================================
void foo() {}
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
        call    bar()
        mov     eax, 0
        pop     rbp
        ret
.LFE2:
*/
