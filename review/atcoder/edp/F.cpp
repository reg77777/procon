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

  string s,t;
  cin>>s>>t;
  vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
  vector<vector<pii>>pre(s.size()+1,vector<pii>(t.size()+1,{0,0}));
  for(int i=1;i<=s.size();i++){
    for(int j=1;j<=t.size();j++){
      if(s[i-1]==t[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
        pre[i][j]={i-1,j-1};
      }
      else if(dp[i-1][j]>dp[i][j-1]){
        dp[i][j]=dp[i-1][j];
        pre[i][j]={i-1,j};
      }
      else{
        dp[i][j]=dp[i][j-1];
        pre[i][j]={i,j-1};
      }
    }
  }
  pii a={s.size(),t.size()};
  vector<pii>ans;
  while(a!=pii({0,0})){
    ans.push_back(a);
    a=pre[a.first][a.second];
  }
  string res="";
  for(int i=0;i<ans.size();i++){
    if(s[ans[i].first-1]==t[ans[i].second-1])res=s[ans[i].first-1]+res;
  }
  cout<<res<<endl;
  return 0;
}
