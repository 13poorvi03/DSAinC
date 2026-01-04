////       1
////     2 1 2
////   3 2 1 2 3
//// 4 3 2 1 2 3 4



#include <stdio.h>
int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // spaces
        for (int j = i; j < n; j++) {
            printf("  "); // two spaces for alignment
        }

        // descending numbers
        for (int k = i; k >= 1; k--) {
            printf("%d ", k);
        }

        // ascending numbers (start from 2 to avoid repeating 1)
        for (int m = 2; m <= i; m++) {
            printf("%d ", m);
        }

        printf("\n");
    }

    return 0;
}