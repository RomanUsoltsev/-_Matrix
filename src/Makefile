GCC = gcc -D_GNU_SOURCE -std=c11 #-Wall -Werror -Wextra

TST = test/
BI = build/
UNAME := $(shell uname)


GCOV = -fprofile-arcs -ftest-coverage
FLAGS = -lcheck

ifeq ($(UNAME),Darwin)
    FLAGS = -lcheck
endif

ifeq ($(UNAME),Linux)
    FLAGS = -lcheck -lcheck_pic -lpthread -lrt -lm -lsubunit
endif

#PROGECT_______________________________________PROGECT
SOURCE:= *.c
SOURCES := $(wildcard $(SOURCE))
OBJECTS_1 := $(patsubst %.c, %.o, $(SOURCES))
OBJECTS := $(patsubst %, $(BI)%, $(OBJECTS_1))
OBJECTS_2 := $(patsubst %, $(BI)%, $(OBJECTS_1))
#PROGECT_______________________________________PROGECT

.PHONY: all clear.a clear.o clear_test clean test cmatrix.a linters cppcheck leaks gcov_report

default: all

all: clean cmatrix.a test gcov_report

clean: clear.a clear.o clear_test
	rm -rf report $(BI)*.gcno $(BI)*.gcda *.gcno *.gcda

clear.o:
	rm -rf $(BI)*.o *.o
clear.a:
	rm -rf $(BI)*.a
clear_test:
	rm -rf test/tests_matrix.c build/tests_matrix build/my_test

# STATICLIB_________________________________STATICLIB
cmatrix.o: $(OBJECTS)

$(BI)%.o: %.c
	$(GCC) -c $< -o $@

cmatrix.a: cmatrix.o
	ar rcs $(BI)cmatrix.a $(OBJECTS)
	ranlib $(BI)cmatrix.a
	cp $(BI)cmatrix.a $(BI)libcmatrix.a
# STATICLIB_________________________________STATICLIB


# TEST_AND_REPORT_____________________TEST_AND_REPORT
DebugFun.o:
	$(GCC) -c -o $(BI)DebugFun.o debug_fun/DebugFun.c

tests_matrix.c:
	checkmk $(TST)tests_matrix.check> $(TST)tests_matrix.c

test: tests_matrix.c cmatrix.a DebugFun.o
	$(GCC) -c -o $(BI)tests_matrix.o $(TST)tests_matrix.c
	$(GCC) $(BI)tests_matrix.o $(BI)DebugFun.o $(BI)libcmatrix.a $(FLAGS) -o $(BI)tests_matrix
	$(BI)./tests_matrix

cmatrix_tst.o:
	$(GCC) $(GCOV) -c $(SOURCES)

gcov_report: tests_matrix.c DebugFun.o cmatrix_tst.o
	$(GCC) -c -o $(BI)tests_matrix.o $(TST)tests_matrix.c
	$(GCC) $(GCOV)  $(BI)tests_matrix.o $(BI)DebugFun.o $(OBJECTS_1) $(FLAGS) $(SOURSES) -o $(BI)tests_matrix
	@$(BI)./tests_matrix
	@lcov -t "tests_matrix" -o tests_matrix.info -c -d .
	@genhtml -o report tests_matrix.info
	@rm -rf *.gcno *.gcda tests_matrix.* $(BI)tests_matrix *.o $(BI)*.o
# TEST_AND_REPORT_____________________TEST_AND_REPORT

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes $(BI)./tests_matrix

linters:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h test/*.c debug_fun/*.c debug_fun/*.h

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem *.c *.h test/*.c debug_fun/*.c debug_fun/*.h