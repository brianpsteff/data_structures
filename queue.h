struct queue {
	int *queue_array;
	int len;
};

struct queue * alloc_queue(struct queue *);
void push_queue(struct queue *,int);
int pop_queue(struct queue *);
