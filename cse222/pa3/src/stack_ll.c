#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int push_stack(struct node* stack, int num) {
	struct node* new = malloc(sizeof(struct node));
	if (new == NULL) {
		// case Out-of-Memory
		return 0;
	}
	new->data = num;
	new->next = stack->next;
	stack->next = new;
	// case success
	return 1;
}

void print_stack(struct node* stack) {
	if (stack->next == NULL) {
		printf("Stack is Empty\n");
		return;
	}
	printf("TOS>> ");
	_print_ll(stack);
	printf("\n");
}
