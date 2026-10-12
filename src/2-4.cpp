// ============================================================================
// 【说明】：演示利用 inline namespace 实现库的多版本并存与默认版本无缝升级。
// 【重点】：
//   1. V1 为历史版本，V2 被声明为 inline namespace（当前默认版本）
//   2. 外部代码调用 Parent::foo() 时默认路由到 Parent::V2::foo() (v2.0)
//   3. 需要旧版本功能时依然可以通过显式 Parent::V1::foo() 访问
// ============================================================================
namespace V1 {
		void foo() { std::cout << "foo v1.0" << std::endl; }
	}

	inline namespace V2 {
		void foo() { std::cout << "foo v2.0" << std::endl; }
	}
}

int main()
{
	Parent::foo();
}
