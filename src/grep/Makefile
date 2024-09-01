all: s21_grep
CFLAGS= -Wall -Werror -Wextra

s21_grep: parsing.o read_and_processing.o s21_grep.o
	gcc $(CFLAGS) parsing.o read_and_processing.o s21_grep.o -o s21_grep

parsing.o: parsing.c parsing.h
	gcc $(CFLAGS) -c parsing.c

read_and_processing.o: read_and_processing.c read_and_processing.h
	gcc $(CFLAGS) -c read_and_processing.c

s21_grep.o: s21_grep.c
	gcc $(CFLAGS) -c s21_grep.c

tests:
	sh grep_tests.sh

clean:
	rm -rf *.o s21_grep grep.txt mygrep.txt diffres.txt

rebuild: clean all
