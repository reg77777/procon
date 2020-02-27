#!/bin/sh

rm cpp.snip
touch cpp.snip

for dir in alg ds
do
  for var in ${dir}/*.cpp
  do
    title=`echo "${var}" | sed -e 's/'${dir}'\///'`
    v=`cat ${var} | nkf -Ww`
    V=`echo "${v}" | sed  -e '/^#/d' -e '/^using namespace std/d' -e '/^\/\//d' -e 's/^/\t/'`
    V="snippet ${title} ${V}"
    echo "${V}" >> cpp.snip
  done
done
