#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct E{
  int to;
  T cost;
};

template<typename T>
vector<T>dijkstra(vector<vector<E<T>>>g,int s){
  T inf=numeric_limits<T>::max();
  vector<T>d(g.size(),inf);
  using Type=pair<T,int>;
  using Container=vector<Type>;
  using Cmp=greater<Type>;
  priority_queue<Type,Container,Cmp>q; 
  d[s]=0;
  q.push({d[s],s});
  while(!q.empty()){
    T cost=q.top().first;
    int from=q.top().second;
    q.pop();
    if(d[from]!=cost)continue;
    for(auto e:g[from]){
      T next_cost=e.cost+cost;
      if(d[e.to]>next_cost){
        d[e.to]=next_cost;
        q.push({d[e.to],e.to});
      }
    }
  }
  return d;
}
