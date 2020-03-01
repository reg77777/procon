#include <vector>
#include <string>
#include <cstdint>

using namespace std; //ごめんなさい

vector<int> RH(string S,string T){
  int SN=S.size();
  int TN=T.size();
  uint_fast64_t b=1e6+7; 
  uint_fast64_t mod=1e9+7; 
  uint_fast64_t s=0;
  uint_fast64_t t=0;
  uint_fast64_t a=1;
  for(int i=0;i<TN;i++){
    a*=b;
    a%=mod;
  }
  for(int i=0;i<TN;i++){
    s=s*b+S[i];
    s%=mod;
  }
  for(int i=0;i<TN;i++){
    t=t*b+T[i];
    t%=mod;
  }
  vector<int>res;
  if(s==t)res.push_back(0);
  for(int i=0;i+TN<SN;i++){
    s=s*b-S[i]*a+S[i+TN];
    s%=mod;
    if(s==t)res.push_back(i+1);
  }
  return res;
}
