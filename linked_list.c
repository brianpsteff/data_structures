#include <stdio.h>
#include <stdlib.h>

#include <linked_list.h>

/* Simple function to initalize a new LL */
extern struct list_head * create_new_ll() {
	struct list_head *head;
	head=(struct list_head *)malloc(sizeof(struct list_head));
	head->start=(struct node *)malloc(sizeof(struct node));
	return head;
}

/* Responsible for adding new elements to the LL */
extern void add_new_node_ll(struct list_head *head, int data) {

	struct node *temp = head->start;

	/* We haven't started the LL...*/
	if (temp->next == NULL) {
		temp->next = (struct node *)malloc(sizeof(struct node));
		temp->data=data;
	}
	else
	{
		while(temp->next != NULL) {
			temp=temp->next;
		}
		temp->next = (struct node *)malloc(sizeof(struct node));
		temp->data=data;
	}

}

/* Remove a single entry from the LL */
extern void remove_node_ll(struct list_head *head, int data) {	

	struct node *temp = head->start;
	struct node *hold = NULL;

	/*Head node has to be deleted*/
	if(temp->data == data) {
		head->start=temp->next;
		free(temp);
	}
	/*Loop and check all other nodes*/
	hold=temp;
	while(temp->next != NULL) {
		if(temp->data==data) {
			hold->next=temp->next;
			free(temp);
			return;
		}
		hold=temp;
		temp=temp->next;
	}
}

/*Print out the current structure of the LL */
extern void print_out_ll(struct list_head *head) {	

	struct node *temp = head->start;

	fprintf(stdout, "Current linked list\n\n\t");

	while(temp->next != NULL)
	{
		fprintf(stdout, "%d->", temp->data);
		temp=temp->next;
	}
	fprintf(stdout, "NULL\n\n");	
}

/*Return the total elements in the LL*/
extern int total_elements_ll(struct list_head *head) {

	int total = 0;
	struct node *temp = head->start;

	while(temp->next != NULL) {
		total++;
		temp=temp->next;
	}

	return total;
}

/*Find and return the total occurences of an element*/
extern int find_elements_ll(struct list_head *head, int data) {
	int total = 0;

	struct node *temp = head->start;

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

/*Find there is an occurence of an element with in the LL, return 1 if true;
 * return 0 if no occurence; Better best-case complexity compared to
 * find_element_ll()
 */
extern int does_element_exist_ll(struct list_head *head, int data) {
	struct node *temp = head->start;
	
	while(temp->next != NULL) {
		if(temp->data==data)
			return 1;
		temp=temp->next;
	}

	/*Check last element*/
	if(temp->data==data)
		return 1;
	
	return 0;
}

/* Is a list empty? Return 1 if true; 0 else */
int is_list_empty(struct list_head *head) {
	struct node *temp = head->start;
	if(temp->next == NULL) {
		return 1;
	}	
	return 0;
}

void free_ll(struct list_head *head) {
	struct node *temp = head->start;
	struct node *hold = NULL;

	while(temp->next != NULL) {
		hold=temp;
		free(hold);
		temp=temp->next;
	}
	//free(temp);
	free(head);
	printf("List Free!\n");
}
