default: dynamicArrayMain

CFLAGS=-std=c99 -lm

dynamicArray.o: dynamicArray.c dynamicArray.h 
	gcc -Wall -std=c99 -c dynamicArray.c	

dynamicArrayMain: dynamicArray.o
	gcc -Wall -std=c99 -o dynamicArrayMain dynamicArray.o dynamicArrayMain.c 
		
clean:
	rm dynamicArray.o dynamicArrayMain

