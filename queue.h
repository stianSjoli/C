#ifndef HEADER_FILE
#define HEADER_FILE

struct node{
	char elem;
	struct node *next;
};

typedef struct node node_t;

node_t* node_create(char elem);

struct queue{
	node_t* head;
	node_t* tail;
};

typedef struct queue queue_t;

queue_t* queue_create();

void queue_enqueue(queue_t* q, node_t* n);

node_t* queue_dequeue(queue_t* q);

void queue_print(queue_t* qp);

#endif