struct hashtb {
	int **buckets;
};

extern void hashtb_insert(struct hashtb *, int);
extern void hashtb_init(struct hashtb *);
extern int hashtb_data_exists(struct hashtb *, int);
