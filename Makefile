SHELL:=/bin/bash
CC=gcc
CFLAGS=-I. -Wall
LIBCC=ar
LIBFLAGS=-cvq

main: linked_list.o bst.o hash_table.o red_black_tree.o bloom_filter.o main.c 
	$(CC) $(CFLAGS) -o main linked_list.o bst.o hash_table.o red_black_tree.o bloom_filter.o main.c

lib:  linked_list.o bst.o hash_table.o red_black_tree.o bloom_filter.o
	$(LIBCC) $(LIBFLAGS) libdstructs.a linked_list.o bst.o hash_table.o red_black_tree.o bloom_filter.o

test: linked_list.o bst.o hash_table.o red_black_tree.o bloom_filter.o main.c
	$(CC) -g $(CFLAGS) -o main linked_list.o bst.o hash_table.o red_black_tree.o bloom_filter.o main.c
	bash -c "if [ ! -f ./rand_data.txt ]; then ./generate_rand.bash; fi"

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c linked_list.c 

bst.o: bst.c
	$(CC) $(CFLAGS) -c bst.c

hash_table.o: hash_table.c
	$(CC) $(CFLAGS) -c hash_table.c

red_black_tree.o: red_black_tree.c
	$(CC) $(CFLAGS) -c red_black_tree.c

bloom_filter.o: bloom_filter.c
	$(CC) $(CFLAGS) -c bloom_filter.c

clean:
	rm -f *.o main libdstructs.a rand_keys.txt rand_data.txt
