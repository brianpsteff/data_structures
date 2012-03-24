struct node {
	int data;
	struct node *next;
};

/*External functions*/
void add_new_node_ll(struct node *, int);
void remove_node_ll(struct node *, int);
void print_out_ll(struct node *);
int total_elements_ll(struct node *);
int find_elements_ll(struct node *,int);
int does_element_exist_ll(struct node *,int);
struct node * create_new_ll();
