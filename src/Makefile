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

OBJECTS = s21_create_matrix.o\
			s21_remove_matrix.o\
			s21_eq_matrix.o\
			s21_sum_sub_matrix.o\
			s21_mult_matrix_num.o\
			s21_transpose.o\
			s21_calc_complements.o\
			s21_inverse_matrix.o\
			s21_determinant.o



SOURSES = s21_create_matrix.c\
			s21_remove_matrix.c\
			s21_eq_matrix.c\
			s21_sum_sub_matrix.c\
			s21_mult_matrix_num.c\
			s21_transpose.c\
			s21_calc_complements.c\
			s21_inverse_matrix.c\
			s21_determinant.c



# 			debug_fun/debug_fun.c
.PHONY: all clear.a clear.o clear_test clean test s21_matrix.a linters cppcheck leaks gcov_report

default: all

all: clean s21_matrix.a test gcov_report

clean: clear.a clear.o clear_test
	rm -rf report *.gcno

clear.o:
	rm -rf *.o $(BI)*.o
clear.a:
	rm -rf *.a
clear_test:
	rm -rf test/tests_matrix.c build/tests_matrix build/my_test

# STATICLIB_________________________________STATICLIB
s21_matrix.a:
	$(GCC) -c $(SOURSES)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a
	cp s21_matrix.a libs21_matrix.a
# STATICLIB_________________________________STATICLIB


# TEST_AND_REPORT_____________________TEST_AND_REPORT
debug_fun.o:
	$(GCC) -c -o $(BI)debug_fun.o debug_fun/debug_fun.c

tests_matrix.c:
	checkmk $(TST)tests_matrix.check> $(TST)tests_matrix.c

test: tests_matrix.c s21_matrix.a debug_fun.o
	$(GCC) -c -o $(BI)tests_matrix.o $(TST)tests_matrix.c
	$(GCC) $(BI)tests_matrix.o $(BI)debug_fun.o libs21_matrix.a $(FLAGS) -o $(BI)tests_matrix
	$(BI)./tests_matrix

gcov_report: tests_matrix.c s21_matrix.a debug_fun.o
	@gcc -c -o $(BI)tests_matrix.o $(TST)tests_matrix.c
	@gcc $(GCOV)  $(BI)tests_matrix.o $(BI)debug_fun.o $(FLAGS) $(SOURSES) -o tests_matrix
	@./tests_matrix
	@lcov -t "tests_matrix" -o tests_matrix.info -c -d .
	@genhtml -o report tests_matrix.info
	@rm -rf ./*.gcno ./*.gcda ./tests_matrix.* tests_matrix
# TEST_AND_REPORT_____________________TEST_AND_REPORT

leaks: clean test
	CK_FORK=no leaks -atExit -- $(BI)./tests_matrix

linters:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h test/*.c debug_fun/*.c debug_fun/*.h

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem *.c *.h test/*.c debug_fun/*.c debug_fun/*.h