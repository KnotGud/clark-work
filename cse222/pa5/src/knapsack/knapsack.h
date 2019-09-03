#ifndef KNAPSACK_H
#define KNAPSACK_H

#define MAXITEMS 128
#define MAXCAPACITY 1024
#define MAXINPUTSIZE 100

typedef struct item {
	int weight;
	int value;
	char name[100];
} item;

typedef struct result {
	item thisItem;
	int count;
} result;

item* getKnapsackData(char*);
int maxVal(int, item*, result**, result*);

#endif
