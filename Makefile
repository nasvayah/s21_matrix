# all, clean, test, s21_matrix.a, gcov_report
GCC=gcc -g
CFALGS=-Wall -Werror -Wextra -std=c11
SOURCES=*.c
TESTS_SOURCES=TESTS/unit_tests.c
OBJECTS=$(SOURCES:.c=.o)

ifeq ($(shell uname), Linux)
	CHECKFLAGS=-lcheck -lm -lpthread -lrt -lsubunit
#-lsubunit
else
	CHECKFLAGS=-lcheck -lm -lpthread
endif

all: clean s21_matrix.a

s21_matrix.a:
	$(GCC) $(CFALGS) $(SOURCES) -c
	ar rcs s21_matrix.a $(OBJECTS)

test: clean s21_matrix.a
	$(GCC) $(CFALGS) $(TESTS_SOURCES) s21_matrix.a $(CHECKFLAGS) -o s21_matrix
	./s21_matrix

gcov_report: clean s21_matrix.a
	$(GCC) $(CFALGS) $(TESTS_SOURCES) $(SOURCES) s21_matrix.a $(CHECKFLAGS) -fprofile-arcs -ftest-coverage -lgcov -o s21_matrix
	./s21_matrix
	lcov -t "./s21_matrix" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

clean:
	rm -rf s21_matrix *.a $(OBJECTS) TESTS/*.log a.out *.gcno *.gcda report report.info *.dSYM

valgrind: clean test
	valgrind --tool=memcheck --leak-check=yes  ./s21_matrix

clang:
	clang-format -i -style=google $(SOURCES) *.h TESTS/*.c TESTS/*.h

main: clean
	$(GCC) $(CFALGS) $(SOURCES) $(CHECKFLAGS) -o s21_matrix
	./s21_matrix

