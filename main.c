#include <stdio.h>
#include <stdlib.h>

#include <bst.h>
#include <linked_list.h>
#include <hash_table.h>
#include <red_black_tree.h>

/* main.c is a simple test program to excerise various DS's*/

int main(int, char **);
void testLL();
void testBST();
void testHASH();
void testRBT();

int main(int argc, char **argv) {

	//testLL();

	//testBST();

	testHASH();

	//testRBT();

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
  int storeUs[8] = {5,10,15,7,2,12,1,3};
 
	struct bst_node asdf;

	asdf.data=-1;

	for(i=0; i<8; i++) {
    add_new_node_bst(&asdf,storeUs[i]);
  }
	
	fprintf(stdout,"Current Binary Tree:\n\n");
	print_out_bst_breadth(&asdf);
	remove_node_bst(&asdf,10);
	fprintf(stdout,"Current Binary Tree:\n\n");
	print_out_bst_breadth(&asdf);
}


void testRBT() {

  int i;
  int storeUs[8] = {5,10,15,7,2,12,1,3};

  struct red_black_node *head;

	head=create_rbt();

  for(i=0; i<8; i++) {
    insert_node_rbt(head,storeUs[i]);
  }

}


void testHASH() {
	
	struct hashtb *newht;
	newht=NULL;

	newht=hashtb_create();	

	hashtb_add_element(newht,15,15);
	hashtb_add_element(newht,20,29);
	hashtb_add_element(newht,30,39);
	hashtb_add_element(newht,1,7);
	hashtb_add_element(newht,3,2);
	hashtb_add_element(newht,2,2031);
	hashtb_add_element(newht,15,21);

	hashtb_lookup(newht,15);
	hashtb_lookup(newht,3);
	hashtb_lookup(newht,15);

	/*hashtb_insert(&newht,5);
	hashtb_insert(&newht,7);

	check=hashtb_data_exists(&newht,5);
	fprintf(stdout,"CHECK: %d\n",check);
	check=hashtb_data_exists(&newht,7);
	fprintf(stdout,"CHECK: %d\n",check);
	check=hashtb_data_exists(&newht,8);
	fprintf(stdout,"CHECK: %d\n",check);*/
}
