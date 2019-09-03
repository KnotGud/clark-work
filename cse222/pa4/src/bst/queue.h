struct ll_node {
	struct node* data;
	struct ll_node* next;
};

struct ll_node* init_ll();
void destroy_ll(struct ll_node*);
// push_queue pushes a new value to the queue.
void push_queue(struct ll_node*, struct node*);
// pop_top_ll takes the first node off the sentinal and returns the address or NULL
struct node* pop_queue(struct ll_node*);
