#include <bits/stdc++.h>

using namespace std;

template<typename T,T inf>
int lis(vector<T>&v){
  int N=v.size();
  vector<T>dp(N,inf);
  for(int i=0;i<N;i++)*lower_bound(dp.begin(),dp.end(),v[i])=v[i];
  int res=0;
  for(int i=0;i<N;i++)if(dp[i]!=inf)res=i;
  return res+1;
}
