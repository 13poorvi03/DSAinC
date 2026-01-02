//wap to add two matrices without extra matrices
//in this we add both matrices in the first matrices
#include <stdio.h>
int main() {
    int a[3][3], b[3][3];

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

    // Add directly into first matrix (no extra matrix used)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            a[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print the result (stored in 'a')
    printf("\nResultant Matrix after Addition:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}