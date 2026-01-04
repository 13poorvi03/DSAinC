// given an n*m matrix "a", print all elements of te matrix in spiral order (leetcode-54)


#include <stdio.h>

int main() {
    int n, m;
    printf("Enter number of rows (n): ");
    scanf("%d", &n);
    printf("Enter number of columns (m): ");
    scanf("%d", &m);

    int arr[n][m];

    // Input matrix
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Boundaries
    int minr = 0, maxr = n - 1;
    int minc = 0, maxc = m - 1;
    int tne = n * m;   // total number of elements
    int count = 0;

    // Spiral output stored in another matrix
    int spiral[n][m];

    while (count < tne) {
        // Left → Right
        for (int j = minc; j <= maxc && count < tne; j++) {
            spiral[minr][j] = ++count;
        }
        minr++;

        // Top → Bottom
        for (int i = minr; i <= maxr && count < tne; i++) {
            spiral[i][maxc] = ++count;
        }
        maxc--;

        // Right → Left
        for (int j = maxc; j >= minc && count < tne; j--) {
            spiral[maxr][j] = ++count;
        }
        maxr--;

        // Bottom → Top
        for (int i = maxr; i >= minr && count < tne; i--) {
            spiral[i][minc] = ++count;
        }
        minc++;
    }

    // Print spiral matrix form
    printf("\nSpiral Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", spiral[i][j]);
        }
        printf("\n");
    }

    return 0;
}