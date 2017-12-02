#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

node_t* node_create(char c){
	node_t* np = malloc(sizeof(node_t));
	np->elem = c;
	np->next = NULL;
	return np;
}

void node_print(node_t* n){
	printf("%c\n", n->elem);
}

queue_t* queue_create(){
	queue_t* qp = malloc(sizeof(queue_t));
	qp->head = NULL;
	qp->tail = NULL;
	return qp;
}

void queue_enqueue(queue_t* q, node_t* n){
	if(q->head == NULL){
		q->head = n;
		q->tail = n;
	} else {
		q->tail->next = n;
		q->tail = n;
	}
}

node_t* queue_dequeue(queue_t* q){
	if(q->head == NULL){
		return NULL;
	} else {
		node_t* node = node_create(q->head->elem);
		node_t* temp = q->head->next;
		free(q->head);
		q->head = temp;
		return node;
	}
}

void queue_print(queue_t* qp){
	if(qp == NULL){
		printf("%s\n", "empty queue");
	} else {
		node_t* iterator = qp->head;
		while(iterator != NULL){
			node_print(iterator);
			iterator = iterator->next;
		}
	}
}
