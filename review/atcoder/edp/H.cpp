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

  int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0;i<H;i++)cin>>a[i];
  vector<vector<int>>dp(H,vector<int>(W,0));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(i==0&&j==0)dp[0][0]=1;
      if(a[i][j]=='.'){
        if(i-1>=0)dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
        if(j-1>=0)dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
      }
    }
  }
  cout<<dp[H-1][W-1]%MOD<<endl;
  return 0;
} 
