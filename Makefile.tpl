dist: {PN}.cpp
	awk '1;/END:SYSLIB/{exit}' {PN}.cpp > _syslib.cpp
	awk 'f;/END:SYSLIB/{f=1}' {PN}.cpp > _stripped.cpp
	gcc -E -P -C _stripped.cpp > _usrlib.cpp
	cat _syslib.cpp _usrlib.cpp > {PN}_dist.cpp
	rm _*

run:
	g++ {PN}.cpp -o {PN}.out
	./{PN}.out

solution:
	pandoc solution.md -o solution.pdf