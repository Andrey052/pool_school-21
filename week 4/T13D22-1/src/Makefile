all:cipher logging_cipher

clean:
	rm ../build/*
	clear

rebuild:
	../build/cipher
	../build/logging_cipher

cipher:
	gcc -Wall -Wextra -Werror cipher.c -o ../build/cipher -D Q_1

logging_cipher:
	gcc -Wall -Wextra -Werror -c cipher.c logger.c -D D
	gcc  -o ../build/logging_cipher *.o -D D
	rm *.o