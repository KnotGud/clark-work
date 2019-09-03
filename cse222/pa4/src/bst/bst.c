#include <stdio.h>
#include <stdlib.h>
#include "./bst.h"
#include "./queue.h"

// Private methods
struct node* _init_node(int);
struct node* _bst_del_node(struct node*, int);
int _bst_height_recurse(struct node*);


struct node* bst_add(struct node* n, int i) {
	if (n) {
		if (i < n->data) {
			n->left = bst_add(n->left, i);
		} else if (i > n->data) {
			n->right = bst_add(n->right, i);
		} else {
			printf("Error: Number already in tree\n"); 
		}
		return n;
	} else {
		return _init_node(i);
	}
}

struct node* bst_del(struct node* n, int i) {
	if (i < n->data) {
		n->left = bst_del(n->left, i);
		return n;
	} else if (i > n->data) {
		n-> right = bst_del(n->right, i);
		return n;
	} else {
		return _bst_del_node(n, i);
	}
}

void bst_destroy(struct node* n) {
	if (n == NULL) { return; }
	if (n->left) { bst_destroy (n->left); }
	if (n->right) { bst_destroy (n->right); }
	free(n);
}

void bst_print_nlr(struct node* n) {
	if (n == NULL) { return; }
	printf("%i, ", n->data);
	bst_print_nlr(n->left);
	bst_print_nlr(n->right);
}

void bst_print_lnr(struct node* n) {
	if (n == NULL) { return; }
	bst_print_lnr(n->left);
	printf("%i, ", n->data);
	bst_print_lnr(n->right);
}

void bst_print_lrn(struct node* n) {
	if (n == NULL) { return; }
	bst_print_lrn(n->left);
	bst_print_lrn(n->right);
	printf("%i, ", n->data);
}

void bst_print_bfs(struct node* n) {
	if (n == NULL) { return; }
	struct ll_node* s = init_ll();
	push_queue(s, n);
	struct node* temp;
	while (s->next) {
		temp = pop_queue(s);
		printf("%i, ", temp->data);
		if (temp->left) { push_queue(s, temp->left); }
		if (temp->right) { push_queue(s, temp->right); }
	}
	destroy_ll(s);
}

int bst_height(struct node* n) {
	if (n == NULL) { return -1; }
	int lh = _bst_height_recurse(n->left);
	int rh = _bst_height_recurse(n->right);
	if (lh > rh) { return lh; }
	else { return rh; }
}

int bst_contains(struct node* n, int i) {
	if (n == NULL) { return 0; }
	if (i < n->data) { return bst_contains(n->left, i); }
	else if (i > n->data) { return bst_contains(n->right, i); }
	else { return 1; }
}

int bst_is_bal(struct node* n) {
	if (n == NULL) { return 1; }
	int lh = bst_height(n->left);
	int rh = bst_height(n->right);

	if ( abs(lh-rh) <=1 && bst_is_bal(n->left) && bst_is_bal(n->right) ) {
		return 1;
	}
	return 0;
}

// _init_node initializes a node with the data given
struct node* _init_node(int i) {
	struct node* new = malloc(sizeof(struct node));
	new->data = i;
	new->left = NULL;
	new->right = NULL;
	return new;
}

// _bst_height_recurse will recursively add and return the height of a bst
int _bst_height_recurse(struct node* n) {
	if (n == NULL) { return 0; }
	int lh = _bst_height_recurse(n->left);
	int rh = _bst_height_recurse(n->right);

	if (lh > rh) { return 1 + lh; }
	else { return 1 + rh; }
}


// _bst_del_node is a private method used to delete a root without orphaning its children
struct node* _bst_del_node(struct node* root, int i) {
	struct node* temp;
	if (!(root->left)) {
		// Case when left of delete node is clear
		temp = root->right;
		free(root);
	} else if (!(root->right)) {
		// Case when right of delete node is clear
		temp = root->left;
		free(root);
	} else {
		temp = root->left;
		struct node* pre = NULL;
		// find the largest node in left subtree
		while (temp->right) {
			pre = temp;
			temp = temp->right;
		}
		if (pre) { 
			pre->right = temp->left; 
			temp->left = root->left;
		}
		temp->right = root->right;
		free(root);
	}
	return temp;
}

