dist: 1001.cpp
	awk '1;/END:SYSLIB/{exit}' 1001.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1001.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1001_dist.cpp
	rm _*

run:
	g++ 1001.cpp -o 1001.out
	./1001.out

solution:
	pandoc solution.md -o solution.pdf