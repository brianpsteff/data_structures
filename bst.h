struct bst_node {
	int data;
	struct bst_node *left;
	struct bst_node *right;
};

extern void add_new_node_bst(int);
extern void print_out_bst_breadth(struct bst_node *);
extern struct bst_node * get_root();
void recurse_bst_add(struct bst_node *,int);
