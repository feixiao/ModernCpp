// ============================================================================
// 【说明】：演示 C++20 using enum 特性在 switch-case 分支中精简枚举作用域前缀。
// 【重点】：
//   1. 传统写 switch 需重复写 case Color::Red 等繁琐前缀
//   2. C++20 引入 using enum Color 后，分支内可直接缩写为 case Red、Green、Blue
// ============================================================================
enum class Color {
	Red,
	Green,
	Blue
};

const char* ColorToString(Color c)
{
	switch (c)
	{
	case Color::Red: return "Red";
	case Color::Green: return "Green";
	case Color::Blue: return "Blue";
	default:
		return "none";
	}
}

/*

const char* ColorToString(Color c)
{
	switch (c)
	{
	using enum Color;
	case Red: return "Red";
	case Green: return "Green";
	case Blue: return "Blue";
	default:
		return "none";
	}
}

const char* ColorToString(Color c)
{
	switch (c)
	{
	using Color::Red;
	case Red: return "Red";
	case Color::Green: return "Green";
	case Color::Blue: return "Blue";
	default:
		return "none";
	}
}

*/
