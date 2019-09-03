#include <stdio.h>
#include "main.h"

// Private functions
int search_node(struct node*, int);
int get_node(struct node*);
void release_node(struct node*, int);

void init(struct node* ll)  {
	ll[0].data = NIL;
	ll[0].next = NIL;
	ll[0].valid = 1;
	for (int i = 1; i < LL_SIZE;  i++) {
		ll[i].valid = 0;
	}
}

void print(struct node* ll) {
	for (int i = ll[0].next; i != NIL;) {
		printf("%d\n", ll[i].data);
		i = ll[i].next;
	}
}

int add(struct node* ll, int n) {
	int pre = 0;
	int i = ll[0].next;
	while (i != NIL) {
		if (ll[i].data == n) {
			// Case when int is alread in list
			return NIL;
		} else if (ll[i].data > n) {
			break;
		}
		pre = i;
		i = ll[i].next;
	}
	int ni = get_node(ll);
	if (ni == NIL) {
		// case when no more memory
		return 0;
	}
	ll[ni].data = n;
	ll[ni].next = ll[pre].next;
	ll[pre].next = ni;
	// Case when int is added
	return 1;
}

int delete(struct node* ll, int n) {
	int pre = 0;
	int i = ll[0].next;
	while (i != NIL) {
		if (ll[i].data == n) {
			ll[pre].next = ll[i].next;
			release_node(ll, i);
			return 1;
		}
		pre = i;
		i = ll[i].next;
	}
	return 0;
}

int search(struct node* ll, int n) {
	if (search_node(ll, n) == NIL) {
		return 0;
	} else {
		return 1;
	}
}


// search_node looks for a node with data n and returns
// the index of the node searched or NIL.
int search_node(struct node* ll, int n) {
	for (int i = ll[0].next; i != NIL;) {
		if (ll[i].data == n) {
			return i;
		}
		i = ll[i].next;
	}
	return NIL;
}

// get_node acts like malloc in that it finds an available
// available node and returns the index or NIL.
int get_node(struct node* ll) {
	for (int i = 0; i < LL_SIZE; i++) {
		if (ll[i].valid == 0) {
			ll[i].data = 0;
			ll[i].next = 0;
			ll[i].valid = 1;
			return i;
		}
	}
	return NIL;
}

// release_node acts like free in that it sets a node to be
// deleted/reused. It takes the index.
void release_node(struct node* ll, int n) {
	ll[n].valid = 0;
}

