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

  int N;
  cin>>N;
  vector<vector<int>>a(3,vector<int>(N));
  for(int i=0;i<N;i++)cin>>a[0][i]>>a[1][i]>>a[2][i];
  vector<vector<int>>dp(N,vector<int>(3,0));
  for(int i=0;i<3;i++)dp[0][i]=a[i][0];
  for(int i=1;i<N;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(j==k)continue;
        dp[i][j]=max(dp[i][j],dp[i-1][k]+a[j][i]);
      }
    }
  }
  int ans=0;
  for(int i=0;i<3;i++){
    ans=max(ans,dp[N-1][i]);
  }
  cout<<ans<<endl;
  return 0;
}
