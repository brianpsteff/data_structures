#include <stdio.h>
#include <stdlib.h>

#include <queue.h>

/* Allocate the space and initalize the queue structure */
struct queue * alloc_queue(struct queue *my_queue) {
	my_queue=(struct queue *)malloc(sizeof(struct queue));
	my_queue->queue_array=(int *)malloc(sizeof(int)*1);
	my_queue->len=0;
	return my_queue;
}

/* Push and item onto the queue */
void push_queue(struct queue *my_queue, int data) {
	int *temp_queue;
	int i = 0;

	my_queue->len++;
	temp_queue = (int *)malloc(sizeof(int)*(my_queue->len));

	for(i=1;i<my_queue->len;i++) {
		temp_queue[i]=my_queue->queue_array[i-1];
	}
	temp_queue[0] = data;
	free(my_queue->queue_array);

	my_queue->queue_array = (int *)malloc(sizeof(int)*(my_queue->len));

	for(i=0;i<my_queue->len;i++) {
		my_queue->queue_array[i]=temp_queue[i];
	}
	free(temp_queue);
}

/* Pop an item from the queue; LIFO ordering */
int pop_queue(struct queue *my_queue) {
	int data = 0;
	int i = 0;
	int *temp_queue;
	
	my_queue->len--;
	data = my_queue->queue_array[0];

	temp_queue = (int *)malloc(sizeof(int)*(my_queue->len));

	for(i=1;i<my_queue->len+1;i++) {
		temp_queue[i-1]=my_queue->queue_array[i];
	}
	
	free(my_queue->queue_array);

	my_queue->queue_array=(int *)malloc(sizeof(int)*(my_queue->len));
	
	for(i=0;i<my_queue->len;i++) {
		my_queue->queue_array[i]=temp_queue[i];		
	}

	free(temp_queue);

	return data;
}
