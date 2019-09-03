#include <stdio.h>
#include "knapsack.h"

int getCombinedValue(result*);

int maxVal(int capacity, item* items, result** cache, result* results) {
	if (capacity <= 0) return 0;
	int max = 0;
	char * maxName = "";
	for (int i = 0; i < MAXITEMS; i++) {
		int currentValue = items[i].value;
		int currentWeight = items[i].weight;
		char * currentName = items[i].name;

		int nextCapacity = capacity - currentWeight;

		result* previousItems = cache[nextCapacity]; 

		int previousValue = getCombinedValue(previousItems); 
		if (previousValue != 0) {
			previousValue = maxVal(nextCapacity, items, cache, results);
			cache[nextCapacity] = results;
		}
		else {
			results = previousItems;
		}

		int value = previousValue + currentValue;
		if (value > max) {
			max = value;
			maxName = currentName;
		}
	}

	for (int i = 0; i < MAXITEMS; i++) {
		if (results[i].thisItem.name == maxName) {
			results[i].count++;
		}
	}

	return max;
}

int getCombinedValue(result* items) {
	int value = 0;
	for (int i = 0; i < MAXITEMS; i++) {
		if (items[i].thisItem.name != "") {
			value += items[i].thisItem.value * items[i].count;
		}
	}
	return value;
}
