// ============================================================================
// 【说明】：演示 C++11 扩展友元（Extended Friend Declarations）支持类型别名与模板类型形参。
// 【重点】：
//   1. 允许声明 friend T;（模板类型参数作为友元）
//   2. 允许 friend Ct;（typedef/using 别名作为友元），甚至当 T 为内置类型或 void 时被静默忽略而不报错
// ============================================================================
class C;
typedef C Ct;

class X1 {
	friend C;
	friend Ct;
	friend void;
	friend int;
};

template <typename T> class R {
	friend T;
};

R<C> rc;
R<Ct> rct;
R<int> ri;
R<void> rv;
