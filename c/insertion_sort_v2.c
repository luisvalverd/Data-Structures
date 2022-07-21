#include <stdio.h>

/*
    insertion sort
    is a algorithm to sort a array 
    this has complexity of O(n^2)
*/

void printArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%i\n", array[i]);
    }
}

void insertionSort(int A[], int i, int j, int len) {
    if (i < len && j >= 0) {
        if (A[j] > A[j + 1]) {
            int temp = A[j + 1];
            A[j + 1] = A[j];
            A[j] = temp;
        }
        insertionSort(A, i, j - 1, len);
    }
    if (j == 0) {
        insertionSort(A, i + 1, i, len);
    }
}

int main() {
    int A[] = {1, 3, 5, 4, 6, 2, 9, 0, 8, 7}; 
    int len = 10;

    insertionSort(A, 1, 0, len);

    printArray(A, len);
}