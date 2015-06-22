rm enum_class.txt
mkdir -p include.python
rm -rf include.python/* 
cp -rf ../include/* ./include.python/ 
gen-header4dir.py ./include.python/

mkdir -p ./gezi.include.python/ 
rm -rf ./gezi/include.python/*
cp -rf ../../gezi/include/* ./gezi.include.python/ 
gen-header4dir.py ./gezi.include.python/
cp -rf ../../gezi/include/cppformat/* ./gezi.include.python/ 

gen-header4dir-postdeal.py ./include.python/ 
gen-header4dir-postdeal.py ./gezi.include.python/
