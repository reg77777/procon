#!/bin/sh

rm cpp.snip
touch cpp.snip

echo "include others.snip" >> cpp.snip

#$B%G!<%?9=B$$N%9%K%Z%C%H:n@.(B
for var in ds/*.cpp
do
  title=`echo "${var}" | sed -e 's/ds\///' -e 's/.cpp//'`
  v=`cat ${var} | nkf -Ww`
  V=`echo "${v}" | sed  -e '/^#/d' -e '/^using namespace std/d' -e '/^\/\//d' -e 's/^/\t/'`
  V="snippet ${title} ${V}"
  echo "${V}" >> cpp.snip
done

#$B%"%k%4%j%:%`$N%9%K%Z%C%H:n@.(B
for var in alg/*/*.cpp
do
  title=`echo "${var}" | sed -e 's/alg\///' -e 's/.cpp//' -e 's/\//_/'`
  v=`cat ${var} | nkf -Ww`
  V=`echo "${v}" | sed  -e '/^#/d' -e '/^using namespace std/d' -e '/^\/\//d' -e 's/^/\t/'`
  V="snippet ${title} ${V}"
  echo "${V}" >> cpp.snip
done
