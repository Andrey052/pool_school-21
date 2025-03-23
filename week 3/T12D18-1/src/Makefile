FLAGS = -Wall -Wextra -Werror -std=c11

Quest_1 = main_module_entry_point.c print_module.c
Quest_2 = main_module_entry_point.c documentation_module.c
Quest_3 = bst.c bst_create_test.c

all:
	make print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
	clear

rebild:
	../build/Quest_1
	../build/Quest_2
	../build/Quest_3
	../build/Quest_4
	../build/Quest_5

clean:
	rm ../build/*
	clear

print_module:
	gcc -c $(FLAGS) $(Quest_1) -D Q_1
	gcc -o ../build/Quest_1 *.o
	rm *.o

documentation_module:
	gcc -c $(FLAGS) $(Quest_2) -D Q_2
	gcc -o ../build/Quest_2 *.o
	rm *.o

bst_create_test:
	gcc -c $(FLAGS) $(Quest_3) -D Q_3
	gcc -o ../build/Quest_3 *.o
	rm *.o

bst_insert_test:
	gcc -c $(FLAGS) $(Quest_3) -D Q_4
	gcc -o ../build/Quest_4 *.o
	rm *.o

bst_traverse_test:
	gcc -c $(FLAGS) $(Quest_3) -D Q_5
	gcc -o ../build/Quest_5 *.o
	rm *.o

