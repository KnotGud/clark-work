#include <stdio.h>
#include <stdlib.h>
#include "./bst.h"
#include "./queue.h"

struct ll_node* init_ll()  {
	struct ll_node* ll = malloc(sizeof(struct ll_node));
	ll->data = NULL;
	ll->next = NULL;
	return ll;
}

// destroy takes a linked list and will run through the list
// freeing every node including itself.
void destroy_ll(struct ll_node* ll) {
	if (ll->next) { destroy_ll(ll->next); }
	free(ll);
}

struct node* pop_queue(struct ll_node* ll) {
	struct ll_node* ptr = ll->next;
	if (ptr == NULL) {
		// case no nodes in queue
		return NULL;
	}
	ll->next = ptr->next;
	struct node* temp = ptr->data;
	free(ptr);
	// case success
	return temp;
}

void push_queue(struct ll_node* queue, struct node* n) {
	for (; queue->next != NULL;) { queue = queue->next; }
	struct ll_node* new = malloc(sizeof(struct ll_node));
	new->data = n; 
	new->next = NULL;
	queue->next = new;
}

