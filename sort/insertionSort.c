
void insertionSort (int* vector, int size) {
  int i, j, key;
  for (j = 1; j < size; j++) {
    key = vector[j];
    i = j - 1;
    while (i >= 0 && vector[i] > key) {
      vector[i + 1] = vector[i];
      i = i - 1;
    }
    vector[i+1] = key;  
  }
}
