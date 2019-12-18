//構築
//
//反省点:条件を見つけられなかった
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

  int N,K;
  cin>>N>>K;
  if(K>N*(N-1)/2-(N-1)){
    cout<<-1<<endl;
  }
  else{
    vector<pii>ans;
    for(int i=2;i<=N;i++){
      ans.push_back({1,i});
    }
    int c=0;
    for(int i=2;i<=N;i++){
      for(int j=i+1;j<=N;j++){
        if(c>=N*(N-1)/2-(N-1)-K)break;
        ans.push_back({i,j});
        c++;
      }
      if(c>=N*(N-1)/2-(N-1)-K)break;
    }
    cout<<ans.size()<<endl;
    for(auto it:ans){
      cout<<it.first<<" "<<it.second<<endl;
    }
  }
  return 0;
}
