#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int right_most(struct node*);

int largest(struct node* root) {
	return right_most(root->left);
}

int right_most(struct node* root) {
	if (root->right == NULL) {
		return root->data;
	} else {
		return right_most(root->right);
	}
}

