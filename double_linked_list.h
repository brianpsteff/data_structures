struct double_node {
	int data;
	struct double_node *next;
	struct double_node *prev;
};

/*External functions*/
struct double_node * create_new_dll();
void add_new_node_dll(struct double_node *, int);
void remove_node_dll(struct double_node *, int);
void print_out_dll(struct double_node *);
void print_forward_back_dll(struct double_node *, int, int);
