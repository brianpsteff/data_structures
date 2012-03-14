#include <stdio.h>
#include <stdlib.h>

#include <linked_list.h>

struct node *temp = NULL;

extern void add_new_node(struct node *head, int data) {

	/* We haven't started the LL...*/
	if (head->data == -1) {
		temp = (struct node *)malloc(sizeof(struct node));
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

extern void remove_node(struct node *head, int data) {	

	temp = head;

	/*Head node has to be deleted*/
	if(temp->data == data) {
		temp = temp->next;
		head=temp;
	}
	/*Loop and check all other nodes*/
	while(temp->next != NULL) {
		if(temp->next->data == data)
		{
			if(temp->next->next != NULL) {
				free(temp->next);
				temp->next=temp->next->next;
			}
			else {
				free(temp->next);
				temp->next=NULL;
				continue;
			}
		}
		temp=temp->next;
	}
}

extern void print_out_ll(struct node *head) {	

	temp = head;

	fprintf(stdout, "Current linked list\n\n\t");

	while(temp->next != NULL)
	{
		fprintf(stdout, "%d->", temp->data);
		temp=temp->next;
	}
	fprintf(stdout, "%d->NULL\n\n", temp->data);	
}
