struct node {
	int data;
	struct node *next;
};

extern void add_new_node(struct node *, int);
extern void remove_node(struct node *, int);
extern void print_out_ll(struct node *);

