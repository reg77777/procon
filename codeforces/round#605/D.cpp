//反省点 dpの遷移が下手くそ
//
//dpの遷移をちゃんとイメージする!

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

  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int r=0;
  vector<vector<ll>>dp(n,vector<ll>(2));
  dp[0][0]=1;
  dp[0][1]=1;
  for(int i=1;i<n;i++){
    if(a[i-1]<a[i]){
      dp[i][0]=dp[i-1][0]+1;
      if(i-2>=0&&a[i-2]<a[i])dp[i][1]=max(dp[i-1][1]+1,dp[i-2][0]+1);
      else dp[i][1]=dp[i-1][1]+1;
    }
    else{
      if(i-2>=0&&a[i-2]<a[i])dp[i][1]=dp[i-2][0]+1;
      else dp[i][1]=1;
      dp[i][0]=1;
    }
  }
  ll ans=0;
  for(auto it:dp){
    ans=max({ans,it[0],it[1]});
  }
  cout<<ans<<endl;
  return 0;
}
