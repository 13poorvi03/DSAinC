// wap a program to add two matrices

#include <stdio.h>
int main() {
    int a[3][3], b[3][3], sum[3][3];

    // Input first matrix
    printf("Enter elements of first 3x3 matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second 3x3 matrix:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &b[i][j]);
        }
    }

    // Add the two matrices
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print the result
    printf("\nResultant Matrix after Addition:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}