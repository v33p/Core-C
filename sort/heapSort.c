#include "basic-heap.c"

void heapSort (Heap H) {
	initMaxHeap (H);
	int m = H->elements-1;
	int i;
	for (i = m; i > 0; i--) {
		swapHeap (H, 0, i);
		H->elements--;
		maxHeapify (H, 0);
	}
	H->elements = m + 1;
}
