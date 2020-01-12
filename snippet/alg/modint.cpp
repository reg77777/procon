#include <iostream>

template<std::uint_fast64_t mod>
struct modint{
  using u64=int_fast64_t;
  u64 a;
  constexpr modint(const u64 x=0) noexcept:a(x%mod){}

  constexpr modint operator+(const modint obj)const noexcept{return modint(*this)+=obj;}
  constexpr modint operator-(const modint obj)const noexcept{return modint(*this)-=obj;}
  constexpr modint operator*(const modint obj)const noexcept{return modint(*this)*=obj;}
  constexpr modint operator/(const modint obj)const noexcept{return modint(*this)/=obj;}

  constexpr modint&operator+=(const modint obj)noexcept{
    a+=obj.a;
    if(a>=mod)a-=mod;
    return *this;
  }
  constexpr modint&operator++(const modint obj)noexcept{
    a++;
    if(a>=mod)a-=mod;
    return *this;
  } 
  constexpr modint&operator-=(const modint obj)noexcept{
    if(a<obj.a)a+=mod;
    a-=obj.a;
    return *this;
  }
  constexpr modint&operator--(const modint obj)noexcept{
    if(a<1)a+=mod;
    a--;
    return *this;
  } 
  constexpr modint&operator*=(const modint obj)noexcept{
    a=a*obj.a%mod;
    return *this;
  }
  constexpr modint&operator/=(modint obj)noexcept{
    //a^(-1)=a^(mod-2)
    u64 exp=mod-2;
    while(exp){
      if(exp%2)*this*=obj;
      obj*=obj;
      exp/=2;
    }
    return *this;
  }

  friend std::ostream&operator<<(std::ostream&os,const modint&obj)noexcept{
    return os<<obj.a;
  }
  friend std::istream&operator<<(std::istream&is,const modint&obj)noexcept{
    u64 i;
    obj=modint<mod>(i);
    return(is);
  }
};
