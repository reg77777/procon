#include <bits/stdc++.h>

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
