#include <vector>

using namespace std; //ごめんなさい

//square matrix
struct SM{
  vector<vector<int>>m;
  int N;
  SM(vector<vector<int>>m):m(m),N(m.size()){};
  SM operator+(SM obj){
    SM res(vector<vector<int>>(N,vector<int>(N,0)));
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        res.m[i][j]=this->m[i][j]+obj.m[i][j];
      }
    }
    return res;
  }
  SM operator*(SM obj){
    SM res(vector<vector<int>>(N,vector<int>(N,0)));
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        for(int k=0;k<N;k++){
          res.m[i][j]+=this->m[i][k]*obj.m[k][j];
        }
      }
    }
    return res;
  }
  SM pow(int n){
    if(n==0){
      vector<vector<int>>e(N,vector<int>(N,0));
      for(int i=0;i<N;i++)e[i][i]=1;
      return SM(e);
    }
    SM res(vector<vector<int>>(N,vector<int>(N)));
    if(n%2)return (*this)*pow(n-1);
    else{
      SM half=pow(n/2);
      return half*half;
    }
  }
};
