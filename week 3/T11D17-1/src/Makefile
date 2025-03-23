FLAGS = -Wall -Wextra -Werror -std=c11

Quest_1 = dmanager_module.c
Quest_2 = list.c
Quest_3 = stack.c stack_test.c

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

door_struct:
	gcc -c $(FLAGS) $(Quest_1)
	gcc -o ../build/Quest_1 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_1

list_test:
	gcc -c $(FLAGS) $(Quest_2)
	gcc -o ../build/Quest_2 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_2

stack_test:
	gcc -c $(FLAGS) $(Quest_3)
	gcc -o ../build/Quest_3 *.o
	rm *.o
	leaks -atExit -- ../build/Quest_3