sh ./h2interface.sh $1
cat $1 | ./fix-cplusplus11.py > $1.cc 
mv $1.cc  $1
