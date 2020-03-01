#include <vector>
#include <queue>
#include <cstdint>
#include <tuple>

using namespace std; //ごめんなさい

struct E{
  int to;
  int_fast64_t cost;
};

vector<vector<E>>prim(vector<vector<E>>g){
  vector<vector<E>>res(g.size());
  using T=tuple<int_fast64_t,int,int>;
  using C=vector<T>;
  using Cmp=greater<T>;
  priority_queue<T,C,Cmp>q;
  q.push(T(0,0,-1));
  vector<bool>used(g.size(),false);
  while(!q.empty()){
    int_fast64_t cost=get<0>(q.top());
    int now=get<1>(q.top());
    int par=get<2>(q.top());
    q.pop();
    if(used[now])continue;
    used[now]=true;
    if(par!=-1)res[par].push_back({now,cost});
    for(auto e:g[now]){
      q.push(T(e.cost,e.to,now));
    }
  }
  return res;
}
