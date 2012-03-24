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

/*External Functions*/
struct hashtb * hashtb_create();
int hashtb_add_element(struct hashtb *,int,int);
void hashtb_lookup(struct hashtb *,int);

/*Static Functions*/
int get_hash(int, int);
void hashtb_resize(struct hashtb *);
