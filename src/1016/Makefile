dist: 1016.cpp
	awk '1;/END:SYSLIB/{exit}' 1016.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1016.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1016_dist.cpp
	rm _*

run:
	g++ 1016.cpp -o 1016.out
	./1016.out
