#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hash_table.h>

extern struct hashtb * hashtb_create() {
	struct hashtb *newht;
	newht=(struct hashtb *)calloc(1,sizeof(struct hashtb));
	newht->key_num=128;
	newht->key_ratio=4;
	newht->vals=(struct hashtb_element **) calloc(newht->key_num,sizeof(struct hashtb_element *));
	return newht;
}

extern int hashtb_add_element(struct hashtb *table, int key, int data) {

	if((table->key_count / table->key_num) >= table->key_ratio) {
		printf("Must resize table...\n");
		
	}

	size_t hash_val = get_hash(key,256);

	struct hashtb_element *new;
	new = (struct hashtb_element *) calloc(1,sizeof(struct hashtb_element));

	new->key=key;
	new->data=data;

	if(!table->vals[hash_val]) {
		printf("No problems adding element....\n");
		table->vals[hash_val] = new;
		table->key_count++;
	}
	else {
		printf("Collision...\n");
		struct hashtb_element *temp = table->vals[hash_val];
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		table->key_count++;
	}

	return 0;
}

extern int get_hash(int key, int key_max) {
	int i = 0;
	int hash = 0;
	while(i<(key_max/8)) {
		hash ^= i^key_max;
		i++;
	}
	hash = hash % key_max;
	return hash;
}

extern void hashtb_lookup(struct hashtb *table, int key) {
	size_t hash = get_hash(key,256);

	if(!table->vals[hash]) {
		printf("No entries...\n");
		return;
	}

	struct hashtb_element *temp = table->vals[hash];

	while(temp->next != NULL) {
		if(temp->key == key) {
			printf("Found val: %d\n",temp->data);
			return;
		}
		temp=temp->next;
	}
	printf("No keys found...\n");
	return;
}
