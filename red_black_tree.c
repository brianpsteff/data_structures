#include <stdio.h>
#include <stdlib.h>

#include <red_black_tree.h>

/*
 * node->color = 1 => black
 * node->color = 0 => red
 */

extern struct red_black_node* create_rbt() {

	//Hey we have a new rb tree;
	struct red_black_node *temp;
	temp=(struct red_black_node *)malloc(sizeof(struct red_black_node));
	//temp->data=data;
	temp->color=1;
	temp->left=NULL;
	temp->right=NULL;
	
	return(temp);
}

extern void insert_node_rbt(struct red_black_node *root, int data) {
	

}
