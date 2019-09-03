#define NIL -1
#define LL_SIZE 100

struct node {
	int data;
	int next;
	int valid;
};

void init(struct node*);
void print(struct node*);
int add(struct node*, int);
int delete(struct node*, int);
int search(struct node*, int);
