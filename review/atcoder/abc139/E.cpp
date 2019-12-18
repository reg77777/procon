//全探索の高速化
//
//反省点:操作によって変化する部分が少ないことに気づけなかった
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
  vector<vector<int>>A(N,vector<int>(N-1));
  for(int i=0;i<N;i++)for(int j=0;j<N-1;j++)cin>>A[i][j];
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++)A[i][j]--;
    reverse(rng(A[i]));
  }
  vector<pii>q;

  auto check=[&](int i){
    if(A[i].size()==0)return;
    int j=A[i].back();
    if(A[j].size()==0)return;
    if(A[j].back()==i){
      if(i>j)swap(i,j);
      q.push_back({i,j});
    }
  };

  for(int i=0;i<N;i++)check(i);

  int ans=0;
  while(q.size()>0){
    ans++;
    sort(rng(q));
    q.erase((unique(rng(q))),q.end());
    vector<pii>Q;
    swap(Q,q);
    for(auto it:Q){
      int i=it.first;
      int j=it.second;
      A[i].pop_back();
      A[j].pop_back();
      check(i);
      check(j);
    }
  }

  bool ok=true;
  for(int i=0;i<N;i++)if(A[i].size()>0)ok=false;
  if(ok)cout<<ans<<endl;
  else cout<<-1<<endl;
  return 0;
}
