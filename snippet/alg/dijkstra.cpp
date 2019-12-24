//https://ei1333.github.io/luzhiled/snippets/graph/dijkstra.htmlを写した
//O(ElogV)
#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>

struct E{
  int to;
  int cost;
};

std::vector<int>dijkstra(std::vector<std::vector<E>>&g,int s,int inf){
  std::vector<int>d(g.size(),inf);
  using Pi=std::pair<int,int>;
  std::priority_queue<Pi,std::vector<Pi>,std::greater<Pi>>q;
  d[s]=0;
  q.push({d[s],s});
  while(!q.empty()){
    int cost=q.top().first;
    int from=q.top().second;
    q.pop();
    if(d[from]<cost)continue;
    for(auto e:g[from]){
      int next_cost=cost+e.cost;
      if(d[e.to]>next_cost){
        d[e.to]=next_cost;
        q.push({d[e.to],e.to});
      }
    }
  }
  return d;
}

int main(){
  int v,e,r;
  std::cin>>v>>e>>r;
  std::vector<std::vector<E>>g(v);
  for(int i=0;i<e;i++){
    int from,to,cost;
    std::cin>>from>>to>>cost;
    g[from].push_back({to,cost});
  }
  for(auto it:dijkstra(g,r,10000000)){
    std::cout<<it<<std::endl;
  }
  return 0;
}
