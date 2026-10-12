// ============================================================================
// 【说明】：演示传统 C++ 为了规避命名污染而使用类封装内部枚举（模拟强类型枚举）的繁琐方案。
// 【重点】：
//   1. 用 class AuthorityType 将 enum 放在内部并重载运算符
//   2. 说明没有 enum class 时工程上为了类型安全付出的额外包装成本
// ============================================================================
#include <iostream>

class AuthorityType {
 enum InternalType
 {
     ITBan,
     ITGuest,
     ITMember,
     ITAdmin,
     ITSystem,
 };

 InternalType self_;

public:
 AuthorityType(InternalType self) : self_(self) {}

 bool operator < (const AuthorityType &other) const
 {
     return self_ < other.self_;
 }

 bool operator > (const AuthorityType &other) const
 {
     return self_ > other.self_;
 }

 bool operator <= (const AuthorityType &other) const
 {
     return self_ <= other.self_;
 }

 bool operator >= (const AuthorityType &other) const
 {
     return self_ >= other.self_;
 }

 bool operator == (const AuthorityType &other) const
 {
     return self_ == other.self_;
 }

 bool operator != (const AuthorityType &other) const
 {
     return self_ != other.self_;
 }

 const static AuthorityType System, Admin, Member, Guest, Ban;
};

#define DEFINE_AuthorityType(x) const AuthorityType \
 AuthorityType::x(AuthorityType::IT ## x)
DEFINE_AuthorityType(System);
DEFINE_AuthorityType(Admin);
DEFINE_AuthorityType(Member);
DEFINE_AuthorityType(Guest);
DEFINE_AuthorityType(Ban);

int main()
{
 bool b = AuthorityType::System > AuthorityType::Admin;
 std::cout << std::boolalpha << b << std::endl;
}
