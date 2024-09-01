all: s21_cat
CFLAGS= -Wall -Werror -Wextra

s21_cat: parsing.o read_and_processing.o s21_cat.o
	gcc $(CFLAGS) parsing.o read_and_processing.o s21_cat.o -o s21_cat

parsing.o: parsing.c parsing.h
	gcc $(CFLAGS) -c parsing.c

read_and_processing.o: read_and_processing.c read_and_processing.h
	gcc $(CFLAGS) -c read_and_processing.c

s21_cat.o: s21_cat.c
	gcc $(CFLAGS) -c s21_cat.c

tests:
	sh cat_tests.sh

clean:
	rm -rf *.o s21_cat cat.txt mycat.txt diffres.txt

rebuild: clean all
