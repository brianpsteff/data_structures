CC=gcc
CFLAGS=-I. -Wall
LIBCC=ar
LIBFLAGS=-cvq

main: linked_list.o bst.o hash_table.o red_black_tree.o main.c
	$(CC) $(CFLAGS) -o main linked_list.o bst.o hash_table.o red_black_tree.o main.c

lib:  linked_list.o bst.o hash_table.o red_black_tree.o
	$(LIBCC) $(LIBFLAGS) libdstructs.a linked_list.o bst.o hash_table.o red_black_tree.o

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c 

bst.o: bst.c
	$(CC) $(CFLAGS) -c bst.c

hash_table.o: hash_table.c
	$(CC) $(CFLAGS) -c hash_table.c

red_black_tree.o: red_black_tree.c
	$(CC) $(CFLAGS) -c red_black_tree.c

clean:
	rm *.o main libdstructs.a
