#include <stdio.h>
#include <stdlib.h>

#include <bst.h>
#include <linked_list.h>

/* main.c is a simple test program to excerise various DS's*/

int main(int, char **);
void testLL();
void testBST();

int main(int argc, char **argv) {

	testLL();

	testBST();

	return 0;
}

void testLL() {

  int i;
  int storeUs[5] = {5,10,15,7,2};

	struct node head;
	head.data=-1;

  for(i=0; i<5; i++) {
    add_new_node(&head,storeUs[i]);
  }

  print_out_ll(&head);
  remove_node(&head,5);
  print_out_ll(&head);
  remove_node(&head,7);
  print_out_ll(&head);
  remove_node(&head,2);
  print_out_ll(&head);
}

void testBST() {

	int i;
  int storeUs[5] = {5,10,15,7,2};
 
	struct bst_node asdf;

	asdf.data=-1;

	for(i=0; i<5; i++) {
    add_new_node_bst(&asdf,storeUs[i]);
  }
	fprintf(stdout,"Current Binary Tree:\n\n");
	print_out_bst_breadth(&asdf);
}
