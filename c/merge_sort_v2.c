#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    this algorithms is merge sort using sentinels
    the sentinel is used to arrays semi ordered array

        {3, 41, 52, 26, 38, 57, 9, 49}
                /           \
               /             \
    {3, 41, 52, 26}       {38, 57, 9, 49}
       /       \               /      \
      /         \             /        \
   {3, 41}     {52, 26}    {38, 57}  {9, 49}
    /   \       /    \      /   \      /   \
   /     \     /      \    /     \    /     \
  {3}   {41} {52}   {26}  {38}  {57} {9}   {49}
    \    /     \    /       \   /      \   /
     \  /       \  /         \ /        \ / 
    {3, 41}   {26, 52}     {38, 57}   {9, 49}
        \        /            \        /
         \      /              \      /
       {3, 26, 41, 52}      {9, 38, 49, 57}
              \                 /
               \               /
         {3, 9, 26, 38, 41, 49, 52, 57}
*/

void printArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        printf("%i\n", array[i]);
    }
}

int merge(int A[], int init, int middle, int end) {
    int n1 = middle - init + 1;
    int n2 = end - middle;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = A[init + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = A[middle + i + 1];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    int k = init;

    while (k < end + 1) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
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