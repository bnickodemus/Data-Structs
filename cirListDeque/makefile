default: testListDeque

CFLAGS=-std=c99 -lm

cirListDeque.o: cirListDeque.c cirListDeque.h 
	gcc -Wall -std=c99 -c cirListDeque.c	

testListDeque: cirListDeque.o
	gcc -Wall -std=c99 -o testListDeque cirListDeque.o testListDeque.c 
		
clean:
	rm cirListDeque.o testListDeque

