
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <assert.h>

struct tree_node{
	int value;
	struct tree_node *left_node, *right_node;
};

typedef struct tree_node tree_node_t;


tree_node_t* new_node(int value){
	tree_node_t *p = (tree_node_t*) malloc(sizeof(tree_node_t)); 
	p->value = value;
	p->left_node = p->right_node = NULL;
	assert((p->value > 0 || p->value == 0) && p->value < 10);
	return p;
} 

void tree_grow(tree_node_t* parent, int depth){
	if(depth == 0){
		return; 
	}
    parent->left_node = new_node(rand() % 10);
    parent->right_node = new_node(rand() % 10);
    tree_grow(parent->left_node, depth-1);
    tree_grow(parent->right_node, depth-1);
}

void branch_cutting(tree_node_t* current){
	if (current == NULL){
		return;
	}
	branch_cutting(current->left_node);
    branch_cutting(current->right_node);
	free(current);
}

int main (int argc, char **argv) 
{
	tree_node_t *root = new_node(0);
	tree_grow(root, 25);
	printf("tree grown and now freeing the memory...");
	branch_cutting(root);
	printf("tree is removed\n");
	return 0;
}

