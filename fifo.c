#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


int main(int argc, char *argv[]){
	queue_t *q = queue_create();
	queue_enqueue(q, node_create('C'));
	queue_enqueue(q, node_create('A'));
	queue_enqueue(q, node_create('R'));
	queue_enqueue(q, node_create('A'));
	queue_print(q);
	queue_print(NULL);
	printf("\n");
	node_print(queue_dequeue(q));
	printf("\n");
	node_print(queue_dequeue(q));

}

