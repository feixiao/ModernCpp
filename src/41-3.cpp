// ============================================================================
// 【说明】：演示组合逻辑（&&, ||）构建复合约束概念并在类模板实例化中生效。
// 【重点】：
//   1. SignedIntegerType 与 IntegerFloatingType 复合条件约束
//   2. 实参未满足时编译器直接给出清晰的约束不满足错误信息
// ============================================================================
template <SignedIntegerType T>
struct X {};

template <IntegerFloatingType T>
struct Y {};

X<int> x1; 		    // 编译成功
X<unsigned int> x2; // 编译失败

Y<int> y1; 	    // 编译成功
Y<double> y2; 	// 编译成功
