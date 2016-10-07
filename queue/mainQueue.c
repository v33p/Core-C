#include <stdio.h>
#include <stdlib.h>
#include "basic-queue.c"

void doCommand (Queue Q, int command) {
	int value;
	if (command == 1) {
		printQueue (Q);
	}
	else if (command == 2) {
		scanf ("%d", &value);
		enqueue (Q, value);
	}
	else if (command == 3) {
		printf ("%d\n", dequeue (Q));
	}
	else if (command == 4) {
		printf ("%d\n", Q->size);
	}
}

int main (int argc, char** argv) {
	if (argc == 2) {
		int size = atoi (argv[1]);
		Queue Q = initQueue (size);

		int command = 1;
		while (command != 0) {
			scanf ("%d", &command);
			doCommand (Q, command);
		}
	}
	
	return EXIT_SUCCESS;
}	
