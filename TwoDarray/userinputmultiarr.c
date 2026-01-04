#include <stdio.h>

int main() {
    int ar, ac, br, bc;

    printf("Enter the number of rows for first matrix: ");
    scanf("%d", &ar);
    printf("Enter the number of columns for first matrix: ");
    scanf("%d", &ac);

    printf("Enter the number of rows for second matrix: ");
    scanf("%d", &br);
    printf("Enter the number of columns for second matrix: ");
    scanf("%d", &bc);

    // Check multiplication validity
    if (ac != br) {
        printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
        return 0;
    }

    int a[ar][ac], b[br][bc], res[ar][bc];

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < ar; i++) {
        for (int j = 0; j < ac; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < br; i++) {
        for (int j = 0; j < bc; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize result matrix
    for (int i = 0; i < ar; i++) {
        for (int j = 0; j < bc; j++) {
            res[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < ar; i++) {
        for (int j = 0; j < bc; j++) {
            for (int k = 0; k < ac; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < ar; i++) {
        for (int j = 0; j < bc; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}