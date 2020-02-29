#include <vector>
#include <cstdint>
#include <map>

using namespace std; //ごめんなさい

//素数判定
bool isprime(int_fast64_t x){
  for(int i=0;i*i<=x;i++){
    if(x%i==0)return false;
  }
  return true;
}

//素因数分解
map<int_fast64_t,int>prime_factor(int_fast64_t x){
  map<int_fast64_t,int>res;
  for(int_fast64_t i=2;i*i<=x;i++){
    while(x%i==0){
      res[i]++;
      x/=i;
    }
  }
  if(x!=1)res[x]=1;
  return res;
}

//エラストテネスの篩
vector<bool>eratosthenes(int n){
  vector<bool>res(n+1,true);
  res[0]=res[1]=false;
  for(int i=2;i<=n;i++){
    if(res[i])for(int j=i+i;j<=n;j+=i){
      res[j]=false;
    }
  }
  return res;
}
