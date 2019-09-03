#include <stdio.h>
#include <string.h>
#include "./bst/bst.h"

void usage() {
	char* usage = "Available commands:\n#\t\tInsert a number into the bst\nd #\t\tRemoves a number from the bst\ns #\t\tSearch for a number in the bst\nX\t\tPrint bst information\nQ\t\tExit Program\n";
	printf("%s\n", usage);
}

void main() {
	struct node* bst = NULL;
	char input[100];
	char command;
	int num, check;
	int done = 0;

	while(!done) {
		printf(">");
		fgets(input, 99, stdin);
		check = sscanf(input, "%c %d", &command, &num);
		switch (command) {
			case 'Q':
				printf("Exitting Program!\n");
				done = 1;
				bst_destroy(bst);
				break;
			case 'X':
				printf("NLR: "); bst_print_nlr(bst); printf("\n");
				printf("LNR: "); bst_print_lnr(bst); printf("\n");
				printf("LRN: "); bst_print_lrn(bst); printf("\n");
				printf("BFS: "); bst_print_bfs(bst); printf("\n");
				printf("HEIGHT: %i\n", bst_height(bst));
				printf("BALANCED: ");
				if (bst_is_bal(bst)) { printf("YES\n"); }
				else { printf("NO\n"); }
				break;
			case 's':
				if (check != 2) {
					usage();
					break;
				}
				if (bst_contains(bst, num)) { printf("FOUND!\n"); }
				else { printf("NOT FOUND!\n"); }
				break;
			case 'd':
				if (check != 2) {
					usage();
					break;
				}
				if (bst_contains(bst, num)) { bst = bst_del(bst, num); }
				else { printf("NOT FOUND!\n"); }
				break;
			default:
				// check if the input is an integer instead of a command
				check = sscanf(input, "%d", &num);
				if (check != 1) { usage();}
				else { bst = bst_add(bst, num); }
		}
	}
}







