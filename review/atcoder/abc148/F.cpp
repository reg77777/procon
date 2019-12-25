//グラフ上の探索
//
//反省点:グラフの扱いに慣れていなかった
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

  int N,u,v;
  cin>>N>>u>>v,u--,v--;
  vector<int>A(N-1),B(N-1);
  for(int i=0;i<N-1;i++)cin>>A[i]>>B[i],A[i]--,B[i]--;
  vector<vector<int>>G(N);
  for(int i=0;i<N-1;i++){
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  auto Y=[](auto f){
    return [=](auto&&... args){
      return f(f,forward<decltype(args)>(args)...);
    };
  };
  vector<int>t(N,-1),o(N,-1);
  auto tdfs=[&](auto f,int n,int c)->decltype(void()){
    t[n]=c;
    for(auto it:G[n]){
      if(t[it]==-1)f(f,it,c+1);
    }
  };
  auto odfs=[&](auto f,int n,int c)->decltype(void()){
    o[n]=c;
    for(auto it:G[n]){
      if(o[it]==-1)f(f,it,c+1);
    }
  };
  Y(tdfs)(u,0);
  Y(odfs)(v,0);
  vector<int>used(N,false);
  int Max=0;
  auto dfs2=[&](auto f,int n,int c)->decltype(void()){
    used[n]=true;
    Max=max(Max,o[n]);
    for(auto it:G[n]){
      if(!used[it]&&t[it]<o[it])
        f(f,it,c+1);
    }
  };
  Y(dfs2)(u,0);
  cout<<Max-1<<endl;
  return 0;
}
