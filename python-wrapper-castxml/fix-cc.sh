cat $1 | ./add-static-def.py | ./fix-pyplusplus.py | ./fix-abstract-class.py | ./fix-constructor.py | ./fix-pyplusplus-vec.py | ./fix-pyplusplus-map.py | ./fix-add-more-vector.py > $1.ok
mv $1 $1.bak
mv $1.ok $1
