CC=gcc
CFLAGS=-I. -Wall

main: linked_list.o bst.o main.c
	$(CC) $(CFLAGS) -o main linked_list.o bst.o main.c

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c 

bst.o: bst.c
	$(CC) $(CFLAGS) -c bst.c

clean:
	rm *.o main
