#include <stdio.h>
#include <stdlib.h>

#include <linked_list.h>

extern void add_new_node(int);
extern void print_out_ll();

struct node *head = NULL;
struct node *temp = NULL;

extern void add_new_node(int data) {

	/* We haven't started the LL...*/
	if (head == NULL) {
		head = (struct node *)malloc(sizeof(struct node));
		head->data=data;
		head->next=NULL;
		temp=head;
	}
	else
	{
		temp->next = (struct node *)malloc(sizeof(struct node));
		temp=temp->next;
		temp->data=data;
		temp->next=NULL;
	}

}

extern void print_out_ll() {	

	temp = head;

	while(temp->next != NULL)
	{
		fprintf(stdout, "LL Output: %d\n", temp->data);
		temp=temp->next;
	}
	fprintf(stdout, "LL Output: %d\n", temp->data);
	
}
