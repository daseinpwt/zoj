dist: 1005.cpp
	awk '1;/END:SYSLIB/{exit}' 1005.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1005.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1005_dist.cpp
	rm _*

run:
	g++ -std=c++11 1005.cpp -o 1005.out
	./1005.out

solution:
	pandoc solution.md -o solution.pdf
