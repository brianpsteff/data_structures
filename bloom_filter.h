struct bloom_filter {
	int *filter;
};

struct bloom_filter * init_bloom_filter(struct bloom_filter *filter);
void add_to_bloom_filter(struct bloom_filter *, char *);
void search_bloom_filter(struct bloom_filter *, char *);
void hash_bloom_filter(int *,int);
int get_numeric_bloom(char *);
