#include <stdio.h>

// Function to delete element at position 'pos' from array 'arr' of current size 'n'.
// Returns new size after deletion.
int deleteAt(int arr[], int n, int pos) {
    // Validate position
    if (pos < 0 || pos >= n) {
        printf("Deletion failed: invalid position %d.\n", pos);
        return n;
    }

    // Shift elements left from pos+1 to end
    for (int i = pos; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Size decreases by 1
    return n - 1;
}

// Utility: print array elements
void printArray(int arr[], int n) {
    printf("Array (%d): ", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter initial size of array: ");
    scanf("%d", &n);

    int arr[100]; // allocate enough space, but no #define MAX

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);

    // Delete example
    n = deleteAt(arr, n, 2); // delete element at position 2
    printArray(arr, n);

    return 0;
}