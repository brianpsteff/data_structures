CC=gcc

main: linked_list.o bst.o main.c
	$(CC) -o main linked_list.o bst.o main.c

linked_list.o: linked_list.c
	$(CC) -c linked_list.c

bst.o: bst.c
	$(CC) -c bst.c

clean:
	rm *.o main
