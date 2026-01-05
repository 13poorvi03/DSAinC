#include <stdio.h>
int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};  // fixed size array

    // Reverse in-place
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    // Print reversed array
    printf("The reverse array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}