TESTS = ./tests/*.cpp ./tests/*.h
TARGET = tests/test
ALL_FILES = *.cpp *.h tests/*.cpp tests/*.h

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -g -std=c++17

# CHECK LIBRARY FOR LINKING
LDFLAGS = -lgtest -lgtest_main

LCOVFLAGS = --ignore-errors inconsistent --ignore-errors mismatch

# FLAGS FOR COVERING MODULES
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FLAGS FOR VALGRING TEST
VAL = --tool=memcheck --leak-check=yes

# FLAGS FOR CPPCHECK TEST
CPPCHECK = --enable=all --suppress=missingIncludeSystem

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: s21_matrix_oop.a test

s21_matrix_oop.a: $(OBJECTS)
	ar rcs $@ $^
	ranlib $@ 
	rm -f *.o

test: $(TESTS) ./tests/*.h s21_matrix_oop.h s21_matrix_oop.a 
	$(CXX) $(CXXFLAGS) -o $(TARGET) $^ $(LDFLAGS)
	./$(TARGET)

gcov_report: s21_matrix_oop.a
	$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) *.cpp tests/*.cpp -o tests/test $(LDFLAGS) 
	./tests/test
	lcov -t "test" -o report.info -c -d ./ --no-external 
	genhtml -o report report.info 
	rm -f tests/*.gcno tests/*.gcda *.info
	xdg-open ./report/index.html

clean:
	rm -rf *.o tests/*.gcno tests/*.gcda report s21_matrix_oop.a tests/test *.info

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

valgrind: $(TARGET)
	$@ $(VAL) ./$(TARGET)

clang_check:
	clang-format -style=Google -n $(ALL_FILES)

clang_fix:
	clang-format -style=Google -i $(ALL_FILES)

dependencies:
	sudo apt install clang-format
	sudo apt-get install libgtest-dev
	sudo apt install doxygen
	sudo apt-get install graphviz
	sudo apt-get install texlive
