#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hash_table.h>

extern struct hashtb * hashtb_create() {
	struct hashtb *newht;
	newht=(struct hashtb *)calloc(1,sizeof(struct hashtb));
	newht->key_num=128;
	newht->key_ratio=4;
	newht->vals=(struct hashtb_element **) calloc(newht->key_num, \
								sizeof(struct hashtb_element *));
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
		printf("No problems adding element %d....\n",data);
		table->vals[hash_val] = new;
		table->key_count++;
	}
	else {
		printf("Collision with element %d...\n",data);
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
/*Generate hash value from key with some simple shifts */
extern int get_hash(int key, int key_max) {
	key ^= (key >> 20) ^ (key >>12);
	return key^(key>>7)^(key>>4);
}

extern void hashtb_lookup(struct hashtb *table, int key) {
	size_t hash = get_hash(key,256);

	if(!table->vals[hash]) {
		printf("No Entries found for key %d...\n",key);
		return;
	}

	struct hashtb_element *temp = table->vals[hash];

	/*If data is in the first element of the chain*/
	if(temp->next == NULL) {
		if(temp->key == key) {
    	printf("Found val: %d\n",temp->data);
    	return;
		}
	}
	/*Cycle through the chained elements looking for data*/
	printf("For key: %d -- Found vals: ",key);
	while(temp->next != NULL) {
		if(temp->key == key) {
			printf("%d and ",temp->data);
		}
		temp=temp->next;
	}
	printf("%d\n",temp->data);
	return;
}
