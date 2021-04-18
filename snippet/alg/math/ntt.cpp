#include<vector>
#define MOD2 988244353

using namespace std;


template<int m>
int modpow(int x,int n){
  if(n==0)return 1;
  if(n%2)return ((x%m)*(modpow<m>(x,n-1)%m))%m;
  else {
    int half=modpow<m>(x,n/2)%m;
    return (half*half)%m;
  }
}

auto mpow=modpow<MOD2>;

vector<int>ntt(vector<int>a,bool reverse=false){
  int N=a.size();
  if(N==1)return a;
  vector<int>b(N/2),c(N/2),res(N);
  for(int i=0;i<N;i++){
    if(i%2==0)b[i/2]=a[i];
    if(i%2==1)c[i/2]=a[i];
  }
  b=ntt(b,reverse);
  c=ntt(c,reverse);
  int Zeta=1;
  int gu=mpow(3,(MOD2-1)/N);
  if(reverse)gu=mpow(gu,MOD2-2);
  for(int i=0;i<N;i++){
    res[i]=(b[i%(N/2)]+(c[i%(N/2)]*Zeta)%MOD2)%MOD2;
    (Zeta*=gu)%=MOD2;
  }
  return res;
}

vector<int>intt(vector<int>a){
  vector<int>res=ntt(a,true);
  for(auto&it:res)it/=a.size();
  return res;
}
