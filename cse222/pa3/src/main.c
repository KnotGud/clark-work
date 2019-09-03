#include <stdio.h>
#include <string.h>
#include "main.h"

void usage() {
	char* usage = "Available commands:\ns\t\tprint stack and set mode to stack mode\nq\t\tprint queue and set mode to queue mode\np\t\tpops value off head of queue or top of stack depending on mode and prints value\n[number]\tinserts number into stack or queue depending on mode\nQ\t\tExit Program\n";
	printf("%s\n", usage);
}

void main() {
	struct node* queue = init_ll();
	struct node* stack = init_ll();

	char input[100];
	char command;
	int num, check;
	int done = 0;
	char mode = 'S';
	while(!done) {
		printf("[%c]>", mode);
		fgets(input, 99, stdin);
		sscanf(input, "%c", &command);
		switch (command) {
			case 'Q':
				printf("Exitting Program!\n");
				done = 1;
				destroy_ll(queue);
				destroy_ll(stack);
				break;
			case 's':
				mode = 'S';
				printf("Current Stack:\n");
				print_stack(stack);
				break;
			case 'q':
				mode = 'Q';
				printf("Current Queue:\n");
				print_queue(queue);
				break;

			case 'p':
				switch (mode) {
					case 'S':
						check = pop_top_ll(stack, &num);
						break;
					case 'Q':
						check = pop_top_ll(queue, &num);
						break;
				}
				if (check == 1) { printf("Number: %d\n", num); }
				else { printf("List Empty!\n"); }
				break;
			default:
				// check if the input is an integer instead of a command
				check = sscanf(input, "%d", &num);
				if (check != 1) { usage();}
				else {
					switch (mode) {
						case 'S':
							check = push_stack(stack, num);
							break;
						case 'Q':
							check = push_queue(queue, num);
							break;
					}
					if (check == 0) {
						printf("OUT OF SPACE\n");
					}
				}
		}
	}
}







