swig -python -c++ stringutil.i 
swig -python -c++ vector.i
#~/.jumbo/comake/comake2 -P
make clean 
make -j8
mv ./libstringutil.so ./_libstringutil.so
mv ./libvector.so ./_libvector.so
