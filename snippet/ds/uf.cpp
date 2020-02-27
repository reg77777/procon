#include <vector>

using namespace std; //$B$4$a$s$J$5$$(B

//Union Find
//
//0~N-1$B$GE:;zIU$1$i$l$?%N!<%I$KBP$7$F0J2<$N%/%(%j$r<B9T$9$k(B
//1. x$B$H(By$B$rF1$8%0%k!<%W$K$9$k(B
//2. x$B$H(By$B$,F1$8%0%k!<%W$KB0$7$F$$$k$+JV$9(B
struct UF{
  vector<int>p; //p[i]=$B%N!<%I(Bi$B$N?F(B
  vector<int>r; //rank[i]=$B%N!<%I(Bi$B$N%i%s%/(B
  UF(int sz){
    r.resize(sz,0);
    p.resize(sz);
    for(int i=0;i<sz;i++)p[i]=i;
  }
  void u(int x,int y){ //1
    x=root(x);
    y=root(y);
    if(r[x]==r[y])r[x]++;
    if(r[x]>r[y])p[y]=x;
    else p[x]=y;
  }
  int root(int x){
    if(p[x]==x)return x;
    return root(x=p[x]);
  }
  bool isu(int x,int y){ //2
    return root(x)==root(y);
  }
};
