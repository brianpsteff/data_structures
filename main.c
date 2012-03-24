#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <bst.h>
#include <linked_list.h>
#include <hash_table.h>
#include <red_black_tree.h>

#define TEST_DATA_SIZE 1000;

/* main.c is a simple test program to excerise various DS's*/

int main(int, char **);
void testLL();
void testBST();
void testHASH();
void testRBT();

int main(int argc, char **argv) {

	testLL();

	//testBST();

	//testHASH();

	//testRBT();

	return 0;
}

void testLL() {

  int i;
  int storeUs[6] = {5,10,15,7,2,2};

	struct node *head;
	head=NULL;

	head=create_new_ll();

  for(i=0; i<6; i++) {
    add_new_node_ll(head,storeUs[i]);
  }
	printf("The number 2 occurs: %d time(s)\n",find_elements_ll(head,2));
  print_out_ll(head);
  remove_node_ll(head,5);
  print_out_ll(head);
  remove_node_ll(head,7);
  print_out_ll(head);
	printf("Total Elements %d\n",total_elements_ll(head));
  remove_node_ll(head,2);
  print_out_ll(head);
	printf("Total Elements %d\n",total_elements_ll(head));
	printf("The number 2 occurs: %d time(s)\n",find_elements_ll(head,2));
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
	
	int rand, key;
	FILE *fp, *fr;
	char rand_line[10];
	char key_line[10];
	struct timeval start, end;
	struct hashtb *newht;
	newht=NULL;

	newht=hashtb_create();	

	fp=fopen("rand_data.txt","r");
	fr=fopen("rand_keys.txt","r");
	
	gettimeofday(&start,NULL);
	
	while(fgets(rand_line,10,fp) != NULL && fgets(key_line,10,fr) != NULL ) {
		sscanf(rand_line, "%d", &rand);
		sscanf(key_line, "%d", &key);
		hashtb_add_element(newht,key,rand);
	}
	fclose(fp);
	rewind(fr);
	while(fgets(key_line,10,fr) != NULL) {
		sscanf(key_line, "%d", &key);
		hashtb_lookup(newht,key);
	}
	fclose(fr);
	gettimeofday(&end,NULL);
  free(newht);
	printf("Total time: %ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));
	printf("Test complete!\n");
}
