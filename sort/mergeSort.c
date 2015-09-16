#include <limits.h>

void merge (int* V, int first, int middle, int last) {
  int n1 = middle - first + 1;
  int n2 = last - middle;

  int i, j, k;
  
  int* Left = malloc ((n1 + 1) * sizeof (int));
  int* Right = malloc ((n2 + 1) * sizeof (int));

  for (i = 0; i < n1; i++)
    Left[i] = V[first+i];
  for (j = 0; j < n2; j++)
    Right[j] = V[middle+1+j];

  Left[n1] = INT_MAX;
  Right[n2] = INT_MAX;

  i = 0;
  j = 0;
  
  for (k = first; k < last+1; k++) {
    if (Left[i] <= Right[j]) {
      V[k] = Left[i];
      i++;
    }
    else {
      V[k] = Right[j];
      j++;
    }
  }

  free (Left);
  free (Right);
}

void mergeSort (int* V, int first, int last) {
  if (first < last) {
    int middle = (first + last) / 2;
    mergeSort (V, first, middle);
    mergeSort (V, middle+1, last);
    merge (V, first, middle, last);
  }
}
