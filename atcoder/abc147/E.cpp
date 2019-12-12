//反省点 決め打つ発想がでてこなかった
//
//実装時にmapの遅さでTLEした
//実装時にdpの遷移をdp[][][]=dp[][][]にしていて壊れた

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
  vector<vector<int>>A(H,vector<int>(W)),B(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A[i][j];
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>B[i][j];
    }
  }
  vector<vector<vector<int>>>dp(H,vector<vector<int>>(W,vector<int>((80+80)*80+1)));
  dp[0][0][abs(A[0][0]-B[0][0])]=true;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      for(int k=0;k<=(80+80)*80;k++){
        if(i+1<H){
          dp[i+1][j][k]|=dp[i][j][k+abs(A[i+1][j]-B[i+1][j])];
          dp[i+1][j][k]|=dp[i][j][abs(k-abs(A[i+1][j]-B[i+1][j]))];
        }
        if(j+1<W){
          dp[i][j+1][k]|=dp[i][j][k+abs(A[i][j+1]-B[i][j+1])];
          dp[i][j+1][k]|=dp[i][j][abs(k-abs(A[i][j+1]-B[i][j+1]))];
        }
      }
    }
  }
  for(int k=0;k<=(80+80)*80;k++){
    if(dp[H-1][W-1][k]){
      cout<<k;
      break;
    }
  }
  return 0;
}
