dist: 1074.cpp
	awk '1;/END:SYSLIB/{exit}' 1074.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1074.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1074_dist.cpp
	rm _*

run:
	g++ -std=c++11 1074.cpp -o 1074.out
	./1074.out

solution:
	pandoc solution.md -o solution.pdf
