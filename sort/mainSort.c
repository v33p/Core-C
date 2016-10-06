#include <stdio.h>
#include <stdlib.h>
#include "basic-vector.c"
#include "insertionSort.c"
#include "mergeSort.c"

int main (int argc, char** argv) {
  if (argc >= 2) {
    int size = atoi (argv[1]);
    int* V = randomVector (size, 100);

    printf ("randomized: ");
    printVector (V, size);
    
    mergeSort (V, 0, size-1);

    printf ("orderly:    ");
    printVector (V, size);
    
  }
  
  return EXIT_SUCCESS;
}
