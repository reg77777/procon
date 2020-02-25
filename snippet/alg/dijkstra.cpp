#include <vector>
#include <queue>
#include <cstdint>

using namespace std; //ごめんなさい

struct E{
  int to;
  int_fast64_t cost;
};


vector<int_fast64_t>dijkstra(vector<vector<E>>g,int s,int_fast64_t inf){
  vector<int_fast64_t>d(g.size(),inf);
  using T=pair<int_fast64_t,int>;
  using C=vector<T>;
  using Cmp=greater<T>;
  priority_queue<T,C,Cmp>q; 
  d[s]=0;
  q.push({d[s],s});
  while(!q.empty()){
    int_fast64_t cost=q.top().first;
    int from=q.top().second;
    q.pop();
    if(d[from]!=cost)continue;
    for(auto e:g[from]){
      int_fast64_t next_cost=e.cost+cost;
      if(d[e.to]>next_cost){
        d[e.to]=next_cost;
        q.push({d[e.to],e.to});
      }
    }
  }
  return d;
}
