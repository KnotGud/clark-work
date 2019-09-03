/* Written By Daniel Lee
 *
 * This File encapulsates the generation of the items array off a knapsack.data
 */
#include <stdio.h>
#include <stdlib.h>
#include "./knapsack.h"

// Private Functions
char* _readTo(FILE*, char);
item* _initItems();

item* getKnapsackData(char* filename) {
	item* items = _initItems();
	int index = 0;

	char i[MAXINPUTSIZE];
	FILE* f;
	f = fopen(filename, "r");
	if (f == NULL) { return NULL; }
	while ( fgets(i, MAXINPUTSIZE-1, f) != NULL ) {
		int check = sscanf(
			i,
			"%d %d %s",
			&(items[index].weight),
			&(items[index].value),
			&(items[index].name)
		);
		if (check == 3) {
			index++;
		} else {
			items[index].name[0] = '\0';
			items[index].value = 0;
			items[index].weight = 0;
		}
	}
	fclose(f);
	return items;
}

item* _initItems() {
	item* items = malloc(sizeof(item[MAXITEMS]));
	for (int i = 0; i < MAXITEMS; i++) { 
		items[i].name[0] = '\0';
		items[i].value = 0;
		items[i].weight = 0;
	}
}

