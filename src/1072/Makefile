dist: 1072.cpp
	awk '1;/END:SYSLIB/{exit}' 1072.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' 1072.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > 1072_dist.cpp
	rm _*

run:
	g++ -std=c++11 1072.cpp -o 1072.out
	./1072.out

solution:
	pandoc solution.md -o solution.pdf
