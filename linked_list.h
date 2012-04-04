struct node {
	int data;
	struct node *next;
};

struct list_head {
	struct node *start;
};

/*External functions*/
void add_new_node_ll(struct list_head *, int);
void remove_node_ll(struct list_head *, int);
void print_out_ll(struct list_head *);
int total_elements_ll(struct list_head *);
int find_elements_ll(struct list_head *,int);
int does_element_exist_ll(struct list_head *,int);
struct list_head * create_new_ll();
int is_list_empty(struct list_head *);
void free_ll(struct list_head *);
