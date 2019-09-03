#define NIL -1

struct node {
	int data;
	struct node* next;
};


struct node* init_ll();
void _print_ll(struct node*);
void destroy_ll(struct node*);

// pop_top_ll takes the first node off the sentinal and returns its value or NIL
// pop_top_ll returns 0 on Empty-LL Exception and 1 on success
int pop_top_ll(struct node*, int*);
// push_queue treats an ll as a queue and pushes a node to the queue
// push_queue takes a node ptr and the int to insert
// push_queue returns a 0 on Out-of-Memory Exception and 1 on success
int push_queue(struct node*, int);
// print_queue wraps _print_ll to add a head and tail to the output
void print_queue(struct node*);
// push_stack treats an ll as a stack and pushes a node to the stack
// push_stack takes a node ptr and an int to insert
// push_stack returns a 0 on Out-of-Memory Exception and 1 on success
int push_stack(struct node*, int);
// print_stack wraps _print_ll to add a tos tag to the output
void print_stack(struct node*);
