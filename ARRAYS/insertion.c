#include <stdio.h>

// Function to insert 'value' at position 'pos' in array 'arr' of current size 'n'.
// Positions are 0-based. Returns new size after insertion.
int insertAt(int arr[], int n, int pos, int value) {
    // Validate position: allowed range is [0, n]
    if (pos < 0 || pos > n) {
        printf("Insertion failed: invalid position %d.\n", pos);
        return n;
    }

    // Shift elements right from the end to 'pos'
    for (int i = n - 1; i >= pos; --i) {
        arr[i + 1] = arr[i];
    }

    // Place the new value at 'pos'
    arr[pos] = value;

    // Size increases by 1
    return n + 1;
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

    int arr[100]; // we can still allocate a large enough array, but no #define MAX

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);

    // Insert example
    n = insertAt(arr, n, 2, 99); // insert 99 at position 2
    printArray(arr, n);

    return 0;
}