struct node {
	int data;
	struct node *next;
};

/*External functions*/
void add_new_node(struct node *, int);
void remove_node(struct node *, int);
void print_out_ll(struct node *);
struct node * create_new_ll();
int total_ll_elements(struct node *);
