#include <stdio.h>
#include <stdlib.h>
#include "main.h"


struct node* init()  {
	struct node* ll = malloc(sizeof(struct node));
	ll->data = NIL;
	ll->next = NULL;
	return ll;
}

void print(struct node* ll) {
	for (struct node* ptr = ll->next; ptr != NULL;) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int add(struct node* ll, int n) {
	struct node* pre = ll;
	for (struct node* ptr = ll->next; ptr != NULL;) {
		if (ptr->data == n) {
			// Case when int is alread in list
			return NIL;
		} else if (ptr->data > n) {
			break;
		}
		pre = ptr;
		ptr = ptr->next;
	}
	struct node* new = malloc(sizeof(struct node)); 
	if (new == NULL) { 
		// case when no more memory
		return 0;
	}
	new->data = n;
	new->next = pre->next;
	pre->next = new;
	// Case when int is added
	return 1;
}

int delete(struct node* ll, int n) {
	struct node* pre = ll;
	for (struct node* ptr = ll->next; ptr != NULL;) {
		if (ptr->data == n) {
			pre->next = ptr->next;
			free(ptr);
			return 1;
		}
		pre = ptr;
		ptr = ptr->next;
	}
	return 0;
}

int search(struct node* ll, int n) {
	for (struct node* ptr = ll->next; ptr != NULL;) {
		if (ptr->data == n) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

// destroy takes a linked list and will run through the list
// freeing every node including itself.
void destroy(struct node* ll) {
	struct node* pre = ll;
	for (struct node* ptr = ll->next; ptr != NULL;) {
		free(pre);
		pre = ptr;
		ptr = ptr->next;
	}
	free(pre);
}
