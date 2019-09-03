/* PA5 by Bryan Perkins and Daniel Lee
 *
 * Main Written by Daniel Lee
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "./knapsack/knapsack.h"

// Private Functions
result* createResults(item*);
void printResults(result*);

void printUsage(char* progName) {
	printf("Usage: %s [int]\n", progName);
}

int main(int argc, char** argv) {
	if ( argc != 2 ) { 
		printUsage(argv[0]);
		return 1;
	}

	int capacity;
	if ( sscanf(argv[1], "%d", &capacity ) != 1 ) {
		printUsage(argv[0]);
		return 1;
	}
	if ( capacity > MAXCAPACITY ) {
		printf("ERR: Capacity exceeds %d", MAXCAPACITY);
		return 2;
	}

	if ( access("knapsack.data", F_OK ) == -1 ) {
		printf("ERR: knapsack.data does not exist!\n");
		return 3;
	}
	item* items = getKnapsackData("knapsack.data");
	if ( &items == NULL ) {
		printf("ERR: Invalid knapsack.data!\n");
		return 4;
	}

	result* cache[MAXCAPACITY];
	for (int i = 0; i <1024; i++) { cache[i] = createResults(items); }
	result* results = createResults(items);
	int max = maxVal(capacity, items, cache, results);
	printf("Max Value: %d", max);
	printResults(results);

	return 0;
}


// Written by Bryan Perkins
result* createResults(item* items) {
	result results[MAXITEMS];
	for (int i = 0; i < MAXITEMS; i++) {
		if (items[i].name == "") {
			results[i].thisItem.value = 0;
			results[i].thisItem.weight = 0;
			continue;
		} 
		results[i].thisItem = items[i];
		results[i].count = 0;
	}
}

// Written by Bryan Perkins
void printResults(result* results) {
	for (int i = 0; i < MAXITEMS; i++)
	{
		if (results[i].thisItem.name == "") continue;
		printf("%s: %d\n", results[i].thisItem.name, results[i].count);
	}
}

