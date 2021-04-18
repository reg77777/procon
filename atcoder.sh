#!/bin/bash

rm -f {0..9}*

size=6
if [ $# -ge 1 ]; then
  size=$1
fi
echo "$size個のファイルを生成"

files=''
for i in `seq $size`
do
  cp atcoder.cpp $i.cpp
  files=${files}${i}.cpp
  files=${files}' '
  echo $i
done

vim -p $files
