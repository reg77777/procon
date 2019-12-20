#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<int>x(M),y(M);
  for(int i=0;i<M;i++)cin>>x[i]>>y[i];
  vector<vector<int>>G(N);
  for(int i=0;i<M;i++){
    x[i]--,y[i]--;
    G[x[i]].push_back(y[i]);
  }
  vector<bool>used(N,false);

  vector<int>newG;
  auto Y=[](auto f){
    return [=](auto&&... args){
      return f(f,forward<decltype(args)>(args)...);
    };
  };
  auto dfs=[&](auto f,auto n)->decltype(void()){
    used[n]=true;
    for(auto it:G[n]){
      if(used[it])continue;
      f(f,it);
    }
    newG.push_back(n);
    return;
  };
  for(int i=0;i<N;i++){
    if(!used[i])Y(dfs)(i);
  }
  reverse(rng(newG));

  vector<int>dp(N,0);
  dp[0]=0;
  for(int i=0;i<N;i++){
    for(auto it:G[newG[i]]){
      dp[it]=max(dp[it],dp[newG[i]]+1);
    }
  }
  int ans=0;
  for(auto it:dp)ans=max(ans,it);
  cout<<ans<<endl;
  return 0;
}
