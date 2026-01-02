//wap to print the row number having the maximum sum in a given matrix 
#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    // Input matrix
    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int maxSum = 0;
    int rowIndex = 0;

    // Initialize with first row sum
    for (int j = 0; j < m; j++) {
        maxSum += a[0][j];
    }

    // Check remaining rows
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            rowIndex = i;
        }
    }

    printf("Row %d has maximum sum = %d\n", rowIndex, maxSum);

    return 0;
}