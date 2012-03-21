struct hashtb {
	struct hashtb_element **vals;
	int key_count;
	int key_num;
	int key_ratio;
};

struct hashtb_element {
	int key;
	int data;
	struct hashtb_element *next;
};

extern struct hashtb * hashtb_create();
extern int hashtb_add_element(struct hashtb *,int,int);
extern int get_hash(int, int);
extern void hashtb_lookup(struct hashtb *,int);
