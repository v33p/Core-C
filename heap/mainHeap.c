#include <stdio.h>
#include <stdlib.h>
#include "basic-vector.c"
#include "heapSort.c"

int main (int argc, char** argv) {
	if (argc >= 2) {
		int size = atoi (argv[1]);
		int* V = randomVector (size, 100);

		printf ("randomized: ");
		printVector (V, size);
		
		Heap H = initHeap (size);

		int i;
		for (i = 0; i < size; i++)
			insertDataHeap (H, V[i]);

		heapSort (H);
		//initMinHeap (H);

		printf ("orderly:    ");
		printHeap (H);
	}
	
	return EXIT_SUCCESS;
}
