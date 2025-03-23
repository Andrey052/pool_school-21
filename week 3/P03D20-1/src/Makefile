all:
	clang-format -n *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	gcc -Wall -Wextra -Werror -c graph.c lib.c
	gcc *.o -o h
	leaks -atExit -- ./h
	rm *.o

clean:
	rm h
	clear
rebuild: 
	./h