CC=gcc
CFLAGS=-I. -Wall

main: linked_list.o bst.o hash_table.o main.c
	$(CC) $(CFLAGS) -o main linked_list.o bst.o hash_table.o main.c

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c 

bst.o: bst.c
	$(CC) $(CFLAGS) -c bst.c

hash_table.o: hash_table.c
	$(CC) $(CFLAGS) -c hash_table.c

clean:
	rm *.o main
