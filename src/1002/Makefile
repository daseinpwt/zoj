dist: 1002.cpp
	awk '1;/END:SYSLIB/{exit}' 1002.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1002.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1002_dist.cpp
	rm _*

run:
	g++ 1002.cpp -o 1002.out
	./1002.out
