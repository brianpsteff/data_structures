#include <stdio.h>
#include <stdlib.h>

#include <double_linked_list.h>

struct double_node * create_new_dll() {
	struct double_node *root = NULL;
	root=(struct double_node *)malloc(sizeof(struct double_node));
	return root;
}

void add_new_node_dll(struct double_node *root, int val) {

	struct double_node *temp = root;

	if(root->next == NULL) {
		root->data=val;
		root->next=(struct double_node *)malloc(sizeof(struct double_node));
		root->next->prev=root;
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

void remove_node_dll(struct double_node *root, int val) {

}

void print_out_dll(struct double_node *root) {
	while(root->next != NULL) {
		printf("%d->",root->data);
		root=root->next;
	}
	printf("NULL\n");
}
