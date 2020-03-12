#include <vector>
#include <string>
#include <cstdint>

using namespace std;

vector<int> RH(string S,string T){
  int SN=S.size();
  int TN=T.size();
  int_fast64_t b=9973; 
  vector<int_fast64_t>mod={1000000007LL,1000000009LL,1000000021LL}; 
  int M=mod.size();
  vector<int_fast64_t>s(M,0);
  vector<int_fast64_t>t(M,0);
  vector<int_fast64_t>a(M,1);
  for(int i=0;i<TN;i++){
    for(int j=0;j<M;j++){
      a[j]=(a[j]*b)%mod[j];
    }
  }
  for(int i=0;i<TN;i++){
    for(int j=0;j<M;j++){
      s[j]=((s[j]*b)%mod[j]+S[i])%mod[j];
    }
  }
  for(int i=0;i<TN;i++){
    for(int j=0;j<M;j++){
      t[j]=((t[j]*b)%mod[j]+T[i])%mod[j];
    }
  }
  vector<int>res;
  bool ok=true;
  for(int i=0;i<M;i++)if(s[i]!=t[i])ok=false;
  if(ok)res.push_back(0);
  for(int i=0;i+TN<SN;i++){
    ok=true;
    for(int j=0;j<M;j++){
      s[j]=((s[j]*b)%mod[j]-(S[i]*a[j])%mod[j])%mod[j];
      if(s[j]<0)s[j]+=mod[j];
      s[j]=(s[j]+S[i+TN])%mod[j];
      if(s[j]!=t[j])ok=false;
    }
    if(ok)res.push_back(i+1);
  }
  return res;
}
