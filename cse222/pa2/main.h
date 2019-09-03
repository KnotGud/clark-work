#define NIL -1

struct node {
	int data;
	struct node* next;
};


struct node* init();
void print(struct node*);
int add(struct node*, int);
int delete(struct node*, int);
int search(struct node*, int);
void destroy(struct node*);
