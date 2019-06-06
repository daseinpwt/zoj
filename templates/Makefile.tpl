BUILD_DIR = build

.PHONY: dist run check solution clean

{PN}.out: $(BUILD_DIR)
	g++ -std=c++11 -I../../include -o $(BUILD_DIR)/{PN}.out {PN}.cpp

dist: $(BUILD_DIR)
	@awk '1;/END:SYSLIB/{exit}' {PN}.cpp > $(BUILD_DIR)/_syslib.cpp
	@awk 'f;/END:SYSLIB/{f=1}' {PN}.cpp > $(BUILD_DIR)/_stripped.cpp
	@gcc -E -P -C -I../../include $(BUILD_DIR)/_stripped.cpp > $(BUILD_DIR)/_usrlib.cpp
	@cat $(BUILD_DIR)/_syslib.cpp $(BUILD_DIR)/_usrlib.cpp > $(BUILD_DIR)/{PN}_dist.cpp
	@rm $(BUILD_DIR)/_syslib.cpp $(BUILD_DIR)/_stripped.cpp $(BUILD_DIR)/_usrlib.cpp

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

run: {PN}.out $(BUILD_DIR)
	$(BUILD_DIR)/{PN}.out

std: $(BUILD_DIR)
	g++ -w -o $(BUILD_DIR)/std std.cpp

check: {PN}.out std
	./check.sh

solution:
	pandoc solution.md -o solution.pdf

clean:
	rm -rf $(BUILD_DIR)
	rm -rf check