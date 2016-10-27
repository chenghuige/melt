cat $1 | ./remove-cplusplus-comment.py | ./format-cplusplus-code.py > $1.temp
mv $1 $1.bak
mv $1.temp $1
./h2interface.py $1
o=${1/.h/.i}
mv $o $1
