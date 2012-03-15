#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hash_table.h>

extern void hashtb_init(struct hashtb *ht) {
	int i;
	ht->buckets=(int **)malloc(10*sizeof(int));
	for (i = 0; i < 10; i++) {
		ht->buckets[i] = (int *)malloc(2*sizeof(int));
	}
	//memset(ht->buckets,-1,sizeof(ht->buckets[0][0]*2*10));
	/*for (i = 0; i < 10; i++) {
		ht->buckets[0][i] = i;
	}*/
}

extern void hashtb_insert(struct hashtb *ht, int data) {

	int hash;
	hash = data % 15;

	ht->buckets[1][hash] = data;
}

extern int hashtb_data_exists(struct hashtb *ht, int data) {

	int hash;
	hash = data % 15;
if(ht->buckets[1][hash] == data)
	return 1;

	fprintf(stdout,"NOT FOUND\n");
	return 0;
}

