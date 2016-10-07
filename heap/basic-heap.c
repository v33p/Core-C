#include <stdio.h>
#include <stdlib.h>

struct heap {
	int size;
	int elements;
	int* data;
};
typedef struct heap *Heap;

int leftChildHeap (int x) {
	return 2 * x + 1;
}

int rightChildHeap (int x) {
	return 2 * x + 2;
}

int parentHeap (int x) {
	return (x - 1) / 2;
}

void swapHeap (Heap H, int a, int b) {
	int aux = H->data[a];
	H->data[a] = H->data[b];
	H->data[b] = aux;
}

Heap initHeap (int size) {
	Heap H = malloc (sizeof (*H));
	int* data = malloc (size * sizeof (int));
	H->size = size;
	H->elements = 0;
	H->data = data;
}

void insertDataHeap (Heap H, int data) {
	H->data[H->elements] = data;
	H->elements++;
}

void printHeap (Heap H) {
	int i;
	for (i = 0; i < H->elements; i++)
		printf ("%d ", H->data[i]);
	printf ("\n");
}

void maxHeapify (Heap H, int i) {
	int left, right, max;
	left = leftChildHeap (i);
	right = rightChildHeap (i);
	if (left < H->elements && H->data[left] > H->data[i])
		max = left;
	else
		max = i;
	if (right < H->elements && H->data[right] > H->data[max])
		max = right;
	if (max != i) {
		swapHeap (H, max, i);
		maxHeapify (H, max);
	}
}

void initMaxHeap (Heap H) {
	int i;
	for (i = H->elements / 2; i >= 0; i--)
		maxHeapify (H, i);
}

void minHeapify (Heap H, int i) {
	int left, right, min;
	left = leftChildHeap (i);
	right = rightChildHeap (i);
	if (left < H->elements && H->data[left] < H->data[i])
		min = left;
	else
		min = i;
	if (right < H->elements && H->data[right] < H->data[min])
		min = right;
	if (min != i) {
		swapHeap (H, min, i);
		minHeapify (H, min);
	}
}

void initMinHeap (Heap H) {
	int i;
	for (i = H->elements / 2; i >= 0; i--)
		minHeapify (H,i);
}
