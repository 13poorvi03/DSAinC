//given a matrix "a" of dimention n*m and 2 coordinates (l1,r1) and(l2,r2). return the sum of the rectangle from(l1,r1) to(12,r2).

// l1,r1 is starting point
// l2,r2 is ending points

#include <stdio.h>

int rectangleSum(int n, int m, int a[n][m], int l1, int r1, int l2, int r2) {
    int sum = 0;
    // Loop through rows from l1 to l2
    for (int i = l1; i <= l2; i++) {
        // Loop through columns from r1 to r2
        for (int j = r1; j <= r2; j++) {
            sum += a[i][j];  // Add element to sum
        }
    }
    return sum;
}

int main() {
    int n = 4, m = 5; // Example matrix size
    int a[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int l1 = 1, r1 = 1; // top-left coordinate
    int l2 = 2, r2 = 3; // bottom-right coordinate

    int result = rectangleSum(n, m, a, l1, r1, l2, r2);
    printf("Rectangle Sum = %d\n", result);

    return 0;
}