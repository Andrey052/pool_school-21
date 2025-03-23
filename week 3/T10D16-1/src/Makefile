FLAGS = -Wall -Wextra -Werror -std=c11

Quest_1 = s21_string.c s21_string_test.c
Quest_8 = s21_string.c text_processor.c

all:
	gcc -c $(FLAGS) *.c
	gcc -o h *.o
	leaks -atExit -- ./h

rebild:
	gcc -c $(FLAGS) *.c
	gcc -o h *.o
	leaks -atExit -- ./h

clean:
	rm *.o
	clear

strlen_tests:
	gcc -c $(Quest_1)
	gcc -o ../build/Quest_1 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_1 1

strcmp_tests:
	gcc -c $(Quest_1)
	gcc -o ../build/Quest_2 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_2 2

strcpy_tests:
	gcc -c $(Quest_1)
	gcc -o ../build/Quest_3 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_3 3

strcat_tests:
	gcc -c $(Quest_1)
	gcc -o ../build/Quest_4 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_4 4

strchr_tests:
	gcc -c $(Quest_1)
	gcc -o ../build/Quest_5 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_5 5

strstr_tests:
	gcc -c  $(Quest_1)
	gcc -o ../build/Quest_6 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_6 6

strtok_tests:
	gcc -c $(Quest_1)
	gcc -o ../build/Quest_7 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_7 7

q8:
	gcc -c $(Quest_8)
	gcc -o ../build/Quest_8 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_8 -w

q8_wrong:
	gcc -c $(Quest_8)
	gcc -o ../build/Quest_8 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_8 -f