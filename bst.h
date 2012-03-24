struct bst_node {
	int data;
	struct bst_node *left;
	struct bst_node *right;
};
/*External functions*/
void add_new_node_bst(struct bst_node *,int);
void print_out_bst_breadth(struct bst_node *);
void remove_node_bst(struct bst_node *, int);
int search_bst(struct bst_node *,int);
struct bst_node * create_new_bst();
