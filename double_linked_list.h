struct double_node {
	int data;
	struct double_node *next;
	struct double_node *prev;
};

struct double_list_head {
	struct double_node *start;
};

/*External functions*/
struct double_list_head * create_new_dll();
void add_new_node_dll(struct double_list_head *, int);
void remove_node_dll(struct double_list_head *, int);
void print_out_dll(struct double_list_head *);
void print_forward_back_dll(struct double_list_head *, int, int);
