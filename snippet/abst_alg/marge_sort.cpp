#include <bits/stdc++.h>

#define INF INT_MAX

//分割統治
template<typename IN,typename OUT>
struct DAC{
  //分割 入力:列 出力:分割された部分列の列
  std::function<std::vector<IN>(IN)>divide;
  //統治 入力:部分列 出力:部分問題の解
  std::function<OUT(IN)>conquer;
  //結合 入力:部分問題の解 出力:結合した問題の解
  std::function<OUT(std::vector<OUT>)>join;

  //分割統治の実行
  OUT slove(IN in){
    std::vector<OUT>outs;
    for(auto division:divide(in)){
      auto res=conquer(division);
      if(res.size())outs.push_back(res);
      else outs.push_back(slove(division));
    }
    OUT out=join(outs);
    return out;
  }
};


//分割
//
//半分
template<typename IN>
std::vector<IN>marge_sort_divide(IN in){
  auto begin=in.begin();
  auto end=in.end();
  std::vector<std::vector<int>>res(2);
  auto it=begin;
  for(;it!=begin+in.size()/2;++it)res[0].push_back(*it);
  for(;it!=begin+in.size();++it)res[1].push_back(*it);
  return res;
}

//統治
//
//要素が1個だったらそのままにする
template<typename IN>
std::vector<int>marge_sort_conquer(IN in){
  std::vector<int>res;
  if(in.size()==1)res.push_back(in[0]);
  return res;
}

//結合
template<typename OUT>
OUT marge_sort_join(std::vector<OUT>outs){
  std::vector<int>res;
  std::vector<int>A=outs[0],B=outs[1];
  int n=A.size()+B.size();
  A.push_back(10000000);
  B.push_back(10000000);
  int a=0,b=0;
  for(int i=0;i<n;i++){
    if(A[a]<=B[b]){
      res.push_back(A[a]);
      a++;
    }
    else{
      res.push_back(B[b]);
      b++;
    }
  }
  return res;
}


int main(){
  //マージソート
  DAC<std::vector<int>,std::vector<int>>dac;
  dac.divide=marge_sort_divide<std::vector<int>>;
  dac.conquer=marge_sort_conquer<std::vector<int>>;
  dac.join=marge_sort_join<std::vector<int>>;

  //適当な入力
  std::vector<int>A={32,23,2,45,56,45,61,3,43,5,6,67,7,8,3,5,76,8,5};
  std::vector<int>a=dac.slove(A);
  for(auto it:a)std::cout<<it<<" ";
  std::cout<<std::endl;
  return 0;
}
