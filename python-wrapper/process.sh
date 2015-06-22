i=melt.py
o=${i/.py/_py.cc} 
rm $o

python $i

rm -rf  ./bak/*include.python
mv ./*include.python ./bak 

cp -rf ../include/ include.python 
cp -rf ../../gezi/include/  gezi.include.python

sh fix-cc.sh $o

export PATH=/home/users/chenghuige/.jumbo/opt/gcc48/bin/:$PATH 
sh ~/tools/bin/make.sh
