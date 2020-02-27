//むずい
#include <vector>

#define INF 1000000000

using namespace std; //ごめんなさい

struct edge{
  int to,cap,rev;
};

struct Flow{
  vector<vector<edge>>G;
  vector<bool>used;
  Flow(vector<vector<edge>>g){
    int N=g.size();
    used.resize(N,false);
    for(int i=0;i<N;i++){
      for(auto it:g[i])add_edge(i,it.to,it.cap);
    }
  };
  void add_edge(int from,int to,int cap){
    G[from].push_back({to,cap,(int)G[to].size()});
    G[to].push_back({from,0,(int)G[from].size()-1});
  }
  int max_flow(int s,int g){
    int flow=0;
    while(true){
      fill(used.begin(),used.end(),false);
      int f=dfs(s,g,INF);
      if(f==0)return flow;
      flow+=f;
    }
  }
  int dfs(int s,int g,int val){
    if(s==g)return val;
    used[s]=true;
    for(auto e:G[s]){
      if(!used[e.to]&&e.cap>0){
        int d=dfs(e.to,g,min(val,e.cap));
        if(d>0){
          e.cap-=d;
          G[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
};

