// Selection sort is a simple comparison-based sorting algorithm that repeatedly finds the smallest (or largest) element from the unsorted part of the array and places it at the beginning, gradually building a sorted portion of the array.

// in this sorting u have to traverse firstly array element one with all the array which one is the minimum in whole array to find minimum elem
// then u have to swap that element with arr[0] then continue this process with other elem
// u have to traverse array i<n-1 

//traverse

//7 4 5 9 8 2 1  (7 & 1)

//1 4 5 9 8 2 7  (2 & 4)

//1 2 5 9 8 4 7  (5 & 4)

//1 2 4 9 8 5 7  (9 & 5)

//1 2 4 5 8 9 7  (8 & 7)

//1 2 4 5 7 9 8  (9 & 8)

//1 2 4 5 7 8 9  
#include <stdio.h>
int main() {
    int arr[7] = {7, 4, 5, 9, 8, 2, 1};
    int n = 7;

    // Selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // assume current index is minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // update minimum index
            }
        }
        // swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Print sorted array
    printf("Sorted array in ascending order:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}