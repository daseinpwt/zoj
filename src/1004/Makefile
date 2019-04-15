dist: 1004.cpp
	awk '1;/END:SYSLIB/{exit}' 1004.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1004.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1004_dist.cpp
	rm _*

run:
	g++ 1004.cpp -o 1004.out
	./1004.out
