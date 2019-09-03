#include <stdio.h>
#include <stdlib.h>
#include "main.h"


struct node* init_ll()  {
	struct node* ll = malloc(sizeof(struct node));
	ll->data = NIL;
	ll->next = NULL;
	return ll;
}

// _print_ll is a partial function that prints the linked list data
void _print_ll(struct node* ll) {
	for (struct node* ptr = ll->next; ptr != NULL;) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

// destroy takes a linked list and will run through the list
// freeing every node including itself.
void destroy_ll(struct node* ll) {
	struct node* pre = ll;
	for (struct node* ptr = ll->next; ptr != NULL;) {
		free(pre);
		pre = ptr;
		ptr = ptr->next;
	}
	free(pre);
}


int pop_top_ll(struct node* ll, int* ret) {
	struct node* ptr = ll->next;
	if (ptr == NULL) {
		// case no nodes in queue
		*ret = NIL;
		return 0;
	}
	ll->next = ptr->next;
	*ret = ptr->data;
	free(ptr);
	// case success
	return 1;
}
