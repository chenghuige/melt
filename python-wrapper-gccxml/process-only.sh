i=melt.py
o=${i/.py/_py.cc} 
rm $o

cp -rf ./bak/*include.python .
python $i

sh fix-cc.sh $o

export PATH=/home/users/chenghuige/.jumbo/opt/gcc48/bin/:$PATH 
sh ~/tools/bin/make.sh
