#include <vector>
#include <bits/stdc++.h>

using namespace std; //ごめんなさい

//TODO 比較演算も受け取りたい
template<typename T,T inf>
int lis(vector<T>v){
  int N=v.size();
  vector<T>dp(N,inf);
  for(int i=0;i<N;i++){
    int l=-1,r=N,m;
    while(r-l>1){
      m=(r+l)/2;
      if(dp[m]<v[i])l=m;
      else r=m;
    }
    dp[r]=min(v[i],dp[r]);
  }
  int res=0;
  for(int i=0;i<N;i++)if(dp[i]!=inf)res=i;
  return res+1;
}


int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  cout<<lis<int,INT_MAX>(A)<<endl;
  return 0;
}
