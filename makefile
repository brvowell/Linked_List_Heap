# Makefile for Assignment 1: Heapsort
# Brandon Vowell

heapsort:	heapsort.o node.o linkedlist.o heap.o dsnode.o
	gcc -Wall -g -std=c99 -o heapsort heapsort.o node.o linkedlist.o heap.o dsnode.o

heapsort.o:		heapsort.c node.h dsnode.h linkedlist.h heap.h
	gcc -Wall -g -std=c99 -c heapsort.c

node.o:		node.c node.h
	gcc -Wall -g -std=c99 -c node.c

dsnode.o:	dsnode.c dsnode.h node.h
	gcc -Wall -g -std=c99 -c dsnode.c

linkedlist.o:	linkedlist.c linkedlist.h node.h dsnode.h
	gcc -Wall -g -std=c99 -c linkedlist.c

heap.o:		heap.c heap.h node.h dsnode.h linkedlist.h
	gcc -Wall -g -std=c99 -c heap.c

clean:
	rm -f heapsort
	rm -rf heapsort.dSYM
	rm -f *.o

run:	heapsort
	heapsort integers
	heapsort -d integers
	heapsort -v integers

