all: build_db
	

clean:
	rm ../build/*
	clear

rebuild:
	../build/module_test

build_db:
	gcc -Wall -Wextra -Werror -c shared.c master_status_events.c master_modules.c master_levels.c modules_db.c
	gcc -o ../build/module_test *.o
	rm *.o