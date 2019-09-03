#include <stdlib.h>

struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode* add(struct tnode *root, int n) {
	struct tnode* new = malloc(sizeof(struct tnode));
	new->data = n;
	if (root->data > n) {root->left = new;}
	if (root->data < n) {root->right = new;}
	return root;
}

