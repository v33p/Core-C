#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

struct queue {
	int* data;
	int front;
	int rear;
	int elements;
	int size;
};
typedef struct queue* Queue;

Bool isQueueEmpty (Queue Q) {
	return Q->elements == 0;
	
//	if (Q->elements == 0)
//		return true;
//	else
//		return false;
}

Bool isQueueFull (Queue Q) {
	return Q->elements == Q->size;

//	if (Q->elements == Q->size)
//        	return true;
// 	else
// 		return false;
}

Queue initQueue (int size) {
	Queue Q = malloc (sizeof *Q);
	Q->front = 0;
	Q->rear = -1;
	Q->elements = 0;
	Q->size = size;
	Q->data = malloc (size * sizeof (int));
}

void printQueue (Queue Q) {
	int i;
	if (isQueueEmpty (Q))
		printf ("empty\n");
	else {
		if (Q->rear >= Q->front) {
			int i;
			for (i = Q->front; i <= Q->rear; i++)
				printf ("%d ", Q->data[i]);
			printf ("\n");
		}
		else {
			int i;
			for (i = Q->front; i < Q->size; i++)
				printf ("%d ", Q->data[i]);
			for (i = 0; i <= Q->rear; i++)
				printf ("%d ", Q->data[i]);
			printf ("\n");	
		}
	}
}

void enqueue (Queue Q, int value) {
	if (!isQueueFull(Q)) {
		if (Q->rear == Q->size -1)
			Q->rear = -1;

		Q->data[++Q->rear] = value;
		Q->elements++;
	}
}

int dequeue (Queue Q) {
	if (!isQueueEmpty(Q)) {
		int result = Q->data[Q->front++];

		if (Q->front == Q->size) 
			Q->front = 0;

		Q->elements--;

		return result;
	}
	else {
		// ERRO
		printf ("Error: Dequeue empty queue\n");
		return -404;
	}
}
