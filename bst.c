#include <stdio.h>
#include <stdlib.h>

#include <bst.h>

/* Simple function to initalize a new BST */
extern struct bst_node * create_new_bst() {
	struct bst_node *root = (struct bst_node *)malloc(sizeof(struct bst_node));
	return root;
}

/* Recursive function to add elements to bst */
extern void add_new_node_bst(struct bst_node *root, int data) {
	
	struct bst_node *new = NULL;

	if(root->data == 0) {
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else {
	if(data < root->data) {
    if(root->left != NULL) {
      root=root->left;
      add_new_node_bst(root,data);
    }
    else {
      new=(struct bst_node *)malloc(sizeof(struct bst_node));
      root->left=new;
      new->data=data;
      new->left=NULL;
      new->right=NULL;
    }
  }
  else
  {
    if(root->right != NULL) {
      root=root->right;
      add_new_node_bst(root,data);
    }
    else {
      new=(struct bst_node *)malloc(sizeof(struct bst_node));
      root->right=new;
      new->data=data;
      new->left=NULL;
      new->right=NULL;
    }
  }
 }
}

/* Recursive function to remove a node from a bst */
extern void remove_node_bst(struct bst_node *root, int data) {
	
	int holder;
	
	if(root->data==data) {
	/*Okay we found the node, get the logical successor*/
		
		if(root->right==NULL) {
			if(root->left==NULL) {
				free(root);
			}
			else {
				holder=root->left->data;
				root->left->data=root->data;
				root->data=holder;
				remove_node_bst(root->left,data);
			}
		}
		else {
			holder=root->right->data;
			root->right->data=root->data;
			root->data=holder;
			remove_node_bst(root->right,data);
		}
	}
	else if(data<root->data) //Go left...
	{	
		remove_node_bst(root->left,data);
	}	
	else //Go right...
	{
		remove_node_bst(root->right,data);
	}
}

/* Recursive function to print out a bst */
extern void print_out_bst_breadth(struct bst_node *root) {
	if(root == NULL) 
		return;
	fprintf(stdout,"%d\n",root->data);
	print_out_bst_breadth(root->left);	
	print_out_bst_breadth(root->right);	
}

/* Function to search a bst */
extern int search_bst(struct bst_node *root, int data) {

	return 2;
}

