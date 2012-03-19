struct red_black_node {
	int data;
	int color;
	struct red_black_node *left;
	struct red_black_node *right;
};

extern void insert_node_rbt(struct red_black_node *, int);
