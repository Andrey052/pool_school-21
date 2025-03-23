LIBS = ../data_libs/*.c  \
	../yet_another_decision_module/decision.c  \
	../main_executable_module/main_executable_module.c \
	../data_module/data_process.c

FLAGS = -Wall -Wextra -Werror -std=c11

BUILD_STAT = ../data_libs/data_io.c  \
	../yet_another_decision_module/decision.c  \
	../main_executable_module/main_executable_module.c \
	../data_module/data_process.c

all:
	gcc -c $(FLAGS) $(LIBS)
	mkdir ../../build/
	gcc -o ../../build/Quest_3 *.o

rebild:
	gcc -c $(FLAGS) $(LIBS)
	gcc -o ../../build/Quest_3 *.o
	leaks -atExit -- ../../build/Quest_3

clean:
	rm *.o
	clear

build_with_static:
	gcc -c $(FLAGS) $(LIBS)
	ar r data_stat.a data_stat.o
	rm data_stat.o
	gcc -o ../../build/Quest_5 *.o data_stat.a
	clear
	leaks -atExit -- ../../build/Quest_5
	rm *.o
	rm *.a

build_with_dynamic:
	gcc -c $(FLAGS) $(LIBS)
	gcc -c -fPIC ../data_module/data_process.c
	gcc -shared -o data_process.so *.o
	rm *.o
	gcc -o ../../build/Quest_6 data_process.so
	clear
	leaks -atExit -- ../../build/Quest_6
	rm *.so 


	