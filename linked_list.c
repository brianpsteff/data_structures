#include <stdio.h>
#include <stdlib.h>

#include <linked_list.h>

int add_new_node(int);
int print_out_ll(struct node *);

item *head = NULL;

int add_new_node(int data) {
	
	item *curr;

	/* We haven't started the LL...*/
	if (head == NULL) {
		head = (struct node *)malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL;
		return 0;
	}
	else
	{
		curr = (struct node *)malloc(sizeof(struct node));
		curr->data=data;
		head->next=curr;
		head=curr;
	}

	return 0;
}
