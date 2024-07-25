CXX = gcc
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++17
LIBS = -lstdc++ -lpthread -lm 
LTEST = -lgtest

GCOVFLAGS = --coverage
SRC = $(wildcard model/*.cc)
OBJS = $(SRC:.cc=.o)
ALL_FILES = **/*.cc **/*.h

BUILD_DIR = build

OS := $(shell uname -s)

ifeq ($(OS),Linux)
	APP_FILE := SmartCalcV2
	OPEN_CMD := xdg-open
else ifeq ($(OS),Darwin)
	APP_FILE := SmartCalcV2.app
	OPEN_CMD := open
endif


.PHONY: all

all: clean install

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LIBS)

install: clean	
	mkdir -p $(BUILD_DIR)
	qmake -o $(BUILD_DIR)/Makefile view/SmartCalcV2.pro
	make -C $(BUILD_DIR)
	make -C $(BUILD_DIR) clean
	rm -rf $(BUILD_DIR)/.qmake.stash $(BUILD_DIR)/Makefile

uninstall:
	rm -rf $(BUILD_DIR)

dist:
	tar -czvf SmartCalcV2.tgz doc README.md $(BUILD_DIR)/$(APP_FILE)
	
dvi: clean
	doxygen
	$(OPEN_CMD) doc/html/index.html

	
gcov_report: clean
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $(SRC) tests/test.cc -o test $(LTEST) $(LIBS)
	./test
	geninfo . -b . -o ./report.info --no-external 
	genhtml report.info -o ./report
	rm -rf *.gcno *.gcov *.gcda *.info *.a *.dSYM tests/*.o
	$(OPEN_CMD) ./report/index.html


tests: $(OBJS)
	$(CXX) $(CXXFLAGS) tests/test.cc $^ -o test $(LTEST) $(LIBS)
	./test

valg: clean tests
	valgrind --tool=memcheck --leak-check=yes ./test

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(ALL_FILES)

clang_check:
	clang-format -style=Google -n $(ALL_FILES)

clang_fix:
	clang-format -style=Google -i $(ALL_FILES)

clean:
	rm -rf *.o main test *.gcno *.gcda *.dSYM model/*.o view/*.o report 
	rm -rf doc dist

dependencies:
	sudo apt install clang-format
	sudo apt install gcovr
	sudo apt install doxygen
	sudo apt-get install libgtest-dev
	sudo apt-get install graphviz
	sudo apt-get install texlive
