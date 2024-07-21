CC = g++
CFLAGS = -Wall -Werror -Wextra -g -lstdc++ -std=c++17 -pedantic
GTEST = -lgtest -lgtest_main -pthread
COVER = -fprofile-arcs -ftest-coverage
ALL_FILES = *.h containers/*.h containersplus/*.h tests/*.cpp
TARGET = test_full

all: test

test: clean
	@ g++ $(CFLAGS) ./tests/*.cpp -o $(TARGET) $(GTEST)
	./$(TARGET)

gcov_report: clean
	@ g++ $(CFLAGS) $(COVER) ./tests/*.cpp -o $(TARGET) $(GTEST)
	./$(TARGET)
	geninfo . -b . -o ./coverage.info --no-external 
	genhtml coverage.info -o ./coverage
	rm -f *.gcno *.gcda *.info
	open coverage/index.html

clean:
	rm -rf *.a *.o *.out
	rm -rf *.info *.gcda *.gcno *.gcov *.gch *.dSYM
	rm -rf coverage
	rm -rf gcov_report report
	rm -rf $(TARGET)

clang_check:
	clang-format -style=Google -n $(ALL_FILES)

clang_fix:
	clang-format -style=Google -i $(ALL_FILES)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config */*.cpp */*.h

valgrind: $(TARGET)
	valgrind ./$(TARGET)

dependencies:
	sudo apt install clang-format
	sudo apt install gcovr
	sudo apt-get install libgtest-dev
	sudo apt-get install graphviz
	sudo apt-get install texlive
