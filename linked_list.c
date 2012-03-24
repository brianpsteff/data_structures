#include <stdio.h>
#include <stdlib.h>

#include <linked_list.h>

/* Simple function to initalize a new LL */
extern struct node * create_new_ll() {
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	return head;
}

/* Responsible for adding new elements to the LL */
extern void add_new_node_ll(struct node *head, int data) {

	struct node *temp = NULL;

	/* We haven't started the LL...*/
	if (head->next == NULL) {
		temp = (struct node *)malloc(sizeof(struct node));
		head->data=data;
		head->next=temp;
	}
	else
	{
		temp = head;
		while(temp->next != NULL) {
			temp=temp->next;
		}
		temp->next = (struct node *)malloc(sizeof(struct node));
		temp=temp->next;
		temp->data=data;
		temp->next=NULL;
	}

}

/* Remove a single entry from the LL */
extern void remove_node_ll(struct node *head, int data) {	

	struct node *temp = NULL;

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

/*Print out the current structure of the LL */
extern void print_out_ll(struct node *head) {	

	struct node *temp = NULL;

	temp = head;

	fprintf(stdout, "Current linked list\n\n\t");

	while(temp->next != NULL)
	{
		fprintf(stdout, "%d->", temp->data);
		temp=temp->next;
	}
	fprintf(stdout, "%d->NULL\n\n", temp->data);	
}

/*Return the total elements in the LL*/
extern int total_elements_ll(struct node *head) {

	int total = 0;
	struct node *temp = NULL;
	temp = head;

	while(temp->next != NULL) {
		total++;
		temp=temp->next;
	}
	total++;

	return total;
}

/*Find and return the total occurences of an element*/
extern int find_elements_ll(struct node *head, int data) {
	int total = 0;

	struct node *temp = NULL;
	temp = head;

	while(temp->next != NULL) {
		if(temp->data==data)
			total++;
		temp=temp->next;
	}
	/*Check the last element*/
	if(temp->data==data) 
      total++;

	return total;
}
