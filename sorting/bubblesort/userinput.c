#include <stdio.h>
int main() {
    int n;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int k = 0; k < n; k++) {
        scanf("%d", &arr[k]);
    }

    // Sorting in ascending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print sorted array
    printf("\nSorted array in ascending order:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}