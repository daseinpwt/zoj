BUILD_DIR = build

.PHONY: dist run check solution clean

dist: $(BUILD_DIR)
	@awk '1;/END:SYSLIB/{exit}' 1029.cpp > $(BUILD_DIR)/_syslib.cpp
	@awk 'f;/END:SYSLIB/{f=1}' 1029.cpp > $(BUILD_DIR)/_stripped.cpp
	@gcc -E -P -C -I../../include $(BUILD_DIR)/_stripped.cpp > $(BUILD_DIR)/_usrlib.cpp
	@cat $(BUILD_DIR)/_syslib.cpp $(BUILD_DIR)/_usrlib.cpp > $(BUILD_DIR)/1029_dist.cpp
	@rm $(BUILD_DIR)/_syslib.cpp $(BUILD_DIR)/_stripped.cpp $(BUILD_DIR)/_usrlib.cpp

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

1029.out: $(BUILD_DIR)
	g++ -std=c++11 -I../../include -o $(BUILD_DIR)/1029.out 1029.cpp

run: 1029.out $(BUILD_DIR)
	$(BUILD_DIR)/1029.out

std: $(BUILD_DIR)
	g++ -w -o $(BUILD_DIR)/std std.cpp

check: 1029.out std
	./check.sh

solution:
	pandoc solution.md -o solution.pdf

clean:
	rm -rf $(BUILD_DIR)
	rm -rf check