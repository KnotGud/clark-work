#include <stdio.h>
#include <string.h>
#include "main.h"

void usage() {
	char* usage = "Available commands:\np\t\tprint list\nx\t\texit program\ni [number]\tinserts number into list in order\ns [number]\tSearches for number in list\nd [number]\tDeletes number from list\n";
	printf("%s\n", usage);
}

void main() {
	struct node* ll = init();

	char input[100];
	char command;
	int num, check;
	int done = 0;
	while(!done) {
		printf(">");
		fgets(input, 99, stdin);
		check = sscanf(input, "%c %d", &command, &num);
		switch (command) {
			case 'x':
				printf("Exitting Program!\n");
				done = 1;
				destroy(ll);
				break;
			case 'p':
				print(ll);
				break;
			case 'i':
				if (check != 2) {
					usage();
					break;
				}
				check = add(ll, num);
				if (check == 1) {
					printf("SUCCESS\n");
				} else if ( check == 0) {
					printf("OUT OF SPACE\n");
				} else if (check == NIL) {
					printf("NODE ALREADY IN LIST\n");
				}
				break;
			case 's':
				if (check != 2) {
					usage();
					break;
				}
				check = search(ll, num);
				if (check) {
					printf("FOUND\n");
				} else {
					printf("NOT FOUND\n");
				}
				break;
			case 'd':
				if (check != 2) {
					usage();
					break;
				}
				check = delete(ll, num);
				if (check) {
					printf("SUCCESS\n");
				} else {
					printf("NODE NOT FOUND\n");
				}
				break;
			default:
				usage();
		}
	}
}
