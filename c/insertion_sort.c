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

int main() {
    int array[] = {1, 3, 5, 4, 6, 2, 9, 0, 8, 7}; 
    int len = 10;
    int key;
    int i;

    for (int j = 1; j < len ; j++) {
        key = array[j]; // this number to order
        i = j - 1;
        while (i >= 0 && array[i] > key) { // compare if key is high to array[i]
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
    printArray(array, len);
}