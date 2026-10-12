// ============================================================================
// 【说明】：通过编译器生成的重载实例化函数观察递归解包的实际调用代码链。
// 【重点】：
//   1. 展开展示不同参数组合下编译器生成的具体 sum 实例化单体函数
// ============================================================================
sum(double arg)
{
  return arg;
}

sum(double arg0, double args1)
{
  return arg0 + sum(args1);
}

sum(int arg1, double args1, double args2)
{
  return arg1 + sum(args1, args2);;
}

int main()
{
	std::cout << sum(1, 5.0, 11.7) << std::endl;
}
