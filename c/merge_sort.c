#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%i\n", array[i]);
    }
}

int merge(int A[], int init, int middle, int end) {
    int n1 = middle - init + 1;
    int n2 = end - middle;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = A[init + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = A[middle + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = init;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < n1) {
        A[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n2) {
        A[k] = R[j];
        j = j + 1;
        k + k + 1;
    }
}

void mergeSort(int A[], int init, int end) {
    if (init < end) {
        int middle = init + (end - init) / 2;
        mergeSort(A, init, middle);
        mergeSort(A, middle + 1, end);
        merge(A, init, middle, end);
    }
}

int main() {
    int A[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 9, 8};

    mergeSort(A, 0, 14);

    printArray(A, 15);
}