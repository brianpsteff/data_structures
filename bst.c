#include <stdio.h>
#include <stdlib.h>

#include <bst.h>

struct bst_node *root;
struct bst_node *temp;

extern void add_new_node_bst(int data) {

	if(root == NULL) {
		root = (struct bst_node *)malloc(sizeof(struct bst_node));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		temp=root;
	}
	else {
		recurse_bst_add(temp,data);
		temp=root;
	}
}

void recurse_bst_add(struct bst_node *present, int data) {

	struct bst_node *new;	

	if(data < present->data) {
		if(present->left != NULL) {
			present=present->left;
			recurse_bst_add(present,data);
		}
		else {
			new=(struct bst_node *)malloc(sizeof(struct bst_node));
			present->left=new;
			new->data=data;
			new->left=NULL;
			new->right=NULL;
		}
	}
	else
	{
    if(present->right != NULL) {
      present=present->right;
      recurse_bst_add(present,data);
    }
    else {
      new=(struct bst_node *)malloc(sizeof(struct bst_node));
      present->right=new;
      new->data=data;
      new->left=NULL;
      new->right=NULL;
    }
	}
}

extern struct bst_node * get_root() {
	return root;
}

extern void print_out_bst_breadth(struct bst_node *temp) {
	if(temp == NULL) {
		return;
	}
	fprintf(stdout,"%d\n",temp->data);
	print_out_bst_breadth(temp->left);	
	print_out_bst_breadth(temp->right);	
}
