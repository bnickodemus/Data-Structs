default: linkedListMain testLinkedList

CFLAGS=-std=c99 -lm

linkedList.o: linkedList.c linkedList.h 
	gcc -Wall -std=c99 -c linkedList.c	

linkedListMain: linkedList.o
	gcc -Wall -std=c99 -o linkedListMain linkedList.o linkedListMain.c 

testLinkedList: linkedList.o
	gcc -Wall -std=c99 -o testLinkedList linkedList.o testLinkedList.c 
		
clean:
	rm linkedList.o linkedListMain testLinkedList

