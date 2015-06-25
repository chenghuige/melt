i=melt.py
o=${i/.py/_py.cc} 
rm $o

python $i

sh fix-cc.sh $o

sh ~/tools/bin/make.sh
