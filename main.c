#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <bst.h>
#include <linked_list.h>
#include <hash_table.h>
#include <red_black_tree.h>
#include <bloom_filter.h>
#include <queue.h>
#include <double_linked_list.h>

#define TEST_DATA_SIZE 1000;

/* main.c is a simple test program to excerise various DS's*/

int main(int, char **);
void testLL();
void testBST();
void testHASH();
void testRBT();
void testBF();
void testQ();
void testDLL();

int main(int argc, char **argv) {

	//testLL();

	//testBST();

	//testHASH();

	//testRBT();

	//testBF();
	
	//testQ();

	testDLL();

	return 0;
}

void testLL() {

  int i;
  int storeUs[6] = {5,10,15,7,2,2};

	struct node *head = NULL;

	head=create_new_ll();

	printf("Is the list empty? %s\n",is_list_empty(head) ? "Yes" : "No");

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
	printf("Does the element 10 exist in the list: %s\n", \
					does_element_exist_ll(head,10) ? "Yes!" : "No");
	printf("Does the element 100 exist in the list: %s\n", \
					does_element_exist_ll(head,100) ? "Yes!" : "No");
	printf("Is the list empty? %s\n",is_list_empty(head) ? "Yes" : "No");
}

void testBST() {

	int i;
  int storeUs[8] = {5,10,15,7,2,12,1,3};
 
	struct bst_node *root = NULL;

	root=create_new_bst();

	for(i=0; i<8; i++) {
    add_new_node_bst(root,storeUs[i]);
  }
	
	fprintf(stdout,"Current Binary Tree:\n\n");
	print_out_bst_breadth(root);
	remove_node_bst(root,10);
	fprintf(stdout,"Current Binary Tree:\n\n");
	print_out_bst_breadth(root);
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

void testBF() {
	/*FILE *fp;
	char dictionary_line[30];*/

	struct bloom_filter *bloom;
	bloom=NULL;

	bloom=init_bloom_filter(bloom);

	add_to_bloom_filter(bloom,"bob");
	add_to_bloom_filter(bloom,"tim");

	search_bloom_filter(bloom,"bob");
	search_bloom_filter(bloom,"alice");
	search_bloom_filter(bloom,"tim");
	search_bloom_filter(bloom,"Tim");

	/*fp = fopen("/usr/share/dict/american-english","r");
	while(fgets(dictionary_line,30,fp) != NULL) {
		add_to_bloom_filter(bloom,dictionary_line);
	}
	fclose(fp);

	search_bloom_filter(bloom,"Centrismmm@@@ZZZzz");*/
}

/* LIFO Based queue test */
void testQ() {
	struct queue *my_queue;
	my_queue=NULL;

	my_queue=alloc_queue(my_queue);

	push_queue(my_queue,5);
	push_queue(my_queue,10);
	push_queue(my_queue,15);
	push_queue(my_queue,20);
	
	printf("Popped from queue: %d\n",pop_queue(my_queue));
	printf("Popped from queue: %d\n",pop_queue(my_queue));

	push_queue(my_queue,35);
	
	printf("Popped from queue: %d\n",pop_queue(my_queue));
	printf("Popped from queue: %d\n",pop_queue(my_queue));
}

void testDLL() {

	struct double_list_head *root=NULL;

	root=create_new_dll();

	add_new_node_dll(root,5);
	add_new_node_dll(root,15);
	add_new_node_dll(root,25);
	add_new_node_dll(root,35);
	
	print_out_dll(root);
	
	print_forward_back_dll(root,3,2);
	
	remove_node_dll(root,25);
	remove_node_dll(root,5);
	print_out_dll(root);

}
