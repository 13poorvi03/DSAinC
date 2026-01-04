#include <stdio.h>
int main() {
    int size;
    printf("Enter size of butterfly: ");
    scanf("%d", &size);

    // Upper half
    for (int i = 1; i <= size; i++) {
        // left stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // spaces
        for (int k = 1; k <= 2*(size - i); k++) {
            printf(" ");
        }
        // right stars
        for (int m = 1; m <= i; m++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half
    for (int n = size; n >= 1; n--) {
        // left stars
        for (int l = 1; l <= n; l++) {
            printf("*");
        }
        // spaces
        for (int p = 1; p <= 2*(size - n); p++) {
            printf(" ");
        }
        // right stars
        for (int q = 1; q <= n; q++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}