struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* bst_add(struct node*, int);
struct node* bst_del(struct node*, int);
void bst_destroy(struct node*);
void bst_print_nlr(struct node*);
void bst_print_lnr(struct node*);
void bst_print_lrn(struct node*);
void bst_print_bfs(struct node*);
int bst_height(struct node*);
// bst_contains is effectively the search function
// returns non-zero if the number is in the bst
int bst_contains(struct node*, int);
int bst_is_bal(struct node*);
