#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int push_queue(struct node* queue, int num) {
	for (; queue->next != NULL;) { queue = queue->next; }
	struct node* new = malloc(sizeof(struct node));
	if (new == NULL) {
		// case no more memory
		return 0;
	}
	new->data = num; 
	new->next = NULL;
	queue->next = new;
	// case success
	return 1;
}

void print_queue(struct node* queue) {
	if (queue->next == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	printf("HEAD>> ");
	_print_ll(queue);
	printf("<<TAIL\n");
}
