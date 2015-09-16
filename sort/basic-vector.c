#include <stdio.h>
#include <stdlib.h>

void printV (int* V, int size) {
  for (int i = 0; i < size; i++)
    printf ("%d ", V[i]);
  printf ("\n");
}

int* readInput (int size) {
  int* V = malloc (size * sizeof (int));
  
  for (int i = 0; i < size; i++) {
    scanf ("%d ", &V[i]);
  }

  return V;
}

int* randomV (int size, int max_rand) {
  int* V = malloc (size * sizeof (int));

  for (int i = 0; i < size; i++) {
    V[i] = rand () % max_rand;
  }

  return V;
}

