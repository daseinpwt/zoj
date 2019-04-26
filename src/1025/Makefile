dist: 1025.cpp
	awk '1;/END:SYSLIB/{exit}' 1025.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1025.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1025_dist.cpp
	rm _*

run:
	g++ -std=c++11 1025.cpp -o 1025.out
	./1025.out

solution:
	pandoc solution.md -o solution.pdf