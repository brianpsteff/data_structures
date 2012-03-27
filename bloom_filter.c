#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bloom_filter.h>

#define HASH_FUNCS 5
#define BLOOM_SIZE 1024

struct bloom_filter * init_bloom_filter(struct bloom_filter *bloom) {

	bloom = (struct bloom_filter *)malloc(sizeof(struct bloom_filter));
	bloom->filter = (int *)calloc(BLOOM_SIZE,sizeof(int));
	return bloom;
}

void add_to_bloom_filter(struct bloom_filter *bloom, char *name) {

	int numeric = 0;
	int i = 0;
	int *set_slots;
	set_slots=(int *)malloc(sizeof(int)*HASH_FUNCS);

	numeric = get_numeric_bloom(name);

	hash_bloom_filter(set_slots,numeric);

	for(i = 0;i<HASH_FUNCS;i++) {
		bloom->filter[set_slots[i]] = 1;
	}
}

void search_bloom_filter(struct bloom_filter *bloom, char *name) {

	int i = 0;
	int numeric = 0;
	int *set_slots;
	set_slots=(int *)malloc(sizeof(int)*HASH_FUNCS);

	numeric = get_numeric_bloom(name);

  hash_bloom_filter(set_slots,numeric);

	for(i = 0;i<HASH_FUNCS;i++) {
		if(bloom->filter[set_slots[i]] != 1)
		{
			printf("%s not found!\n",name);
			return;
		}
	}
	printf("Found %s!!\n",name);
}

void hash_bloom_filter(int *set_slots, int numeric) {
	int i = 0;
	int key = 0;
	//numeric+=10000;
	key=numeric;
	while(i<HASH_FUNCS) {
		key ^= (key >> 20) ^ (key >>12) ^ (key >> i*i*i);
	  key ^= (key>>7)^(key>>4) ^ (i*i*i+155);
		key = key % BLOOM_SIZE;
		//printf("KEY IS: %d\n",key);
		set_slots[i]=key;
		key = numeric;
		i++;
	}
}
int get_numeric_bloom(char *name) {
	int len = 0;
	int i = 0;
	int numeric = 0;

	len=strlen(name);

	for(i=0;i<len;i++) {
		numeric+=(int)name[i];
	}
	return numeric;
}
