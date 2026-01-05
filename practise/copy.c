#include <stdio.h>
int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};  // fixed size array
    int brr[5];

    // Reverse copy
    for (int i = 0; i < n; i++) {
        brr[n - 1 - i] = arr[i];
    }

    // Print reversed array
    printf("The reverse array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", brr[i]);
    }

    return 0;
}