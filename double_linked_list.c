#include <stdio.h>
#include <stdlib.h>

#include <double_linked_list.h>

struct double_list_head * create_new_dll() {
	struct double_list_head *root = NULL;
	root=(struct double_list_head *)malloc(sizeof(struct double_list_head));
	root->start=(struct double_node *)malloc(sizeof(struct double_node));
	return root;
}

void add_new_node_dll(struct double_list_head *root, int val) {

	struct double_node *temp = root->start;

	if(temp->next == NULL) {
		temp->data=val;
		temp->next=(struct double_node *)malloc(sizeof(struct double_node));
		temp->next->prev=root->start;
	}
	else {
		while(temp->next != NULL) {
			temp=temp->next;
		}
		temp->next=(struct double_node *)malloc(sizeof(struct double_node));
		temp->data=val;
		temp->next->prev=temp;
		temp->next->next=NULL;
	}
}

void remove_node_dll(struct double_list_head *root, int val) {

	struct double_node *temp = root->start;
	
	/*Head node must be removed */
	if(temp->data==val) {
		root->start=temp->next;
		free(temp);
		return;
	}

	while(temp->next != NULL) {
		if(temp->data==val) {
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			free(temp);
		}
		temp=temp->next;
	}
}

void print_out_dll(struct double_list_head *root) {
	struct double_node *temp = root->start;
	
	while(temp->next != NULL) {
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void print_forward_back_dll(struct double_list_head *root, int forward, \
															int back) {
	
	struct double_node *temp = root->start;
	int i;

	for(i=0;i<forward;i++) {
		temp=temp->next;
	}
	for(i=0;i<back;i++) {
		temp=temp->prev;
	}
	printf("Val is: %d\n",temp->data);
}
