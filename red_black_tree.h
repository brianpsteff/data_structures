struct red_black_node {
	int data;
	int key;
	int color;
	struct red_black_node *left;
	struct red_black_node *right;
	struct red_black_node *parent;
};

extern struct red_black_node * create_rbt();
extern void insert_node_rbt(struct red_black_node *, int);
