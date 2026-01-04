// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444


#include <stdio.h>
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int size = 2*n - 1;  // total rows and columns

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int min = i;
            if (j < min) min = j;
            if (size - 1 - i < min) min = size - 1 - i;
            if (size - 1 - j < min) min = size - 1 - j;

            printf(" %d ", n - min);
        }
        printf("\n");
    }

    return 0;
}









// #include <stdio.h>
// int main() {
//     int n = 4; // maximum number in pattern

//     int size = 2*n - 1; // total rows and columns

//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < size; j++) {
//             // find minimum distance from any border
//             int top = i;
//             int left = j;
//             int bottom = size - 1 - i;
//             int right = size - 1 - j;

//             int minDist = top;
//             if (left < minDist) minDist = left;
//             if (bottom < minDist) minDist = bottom;
//             if (right < minDist) minDist = right;

//             // value = n - minDist
//             printf(" %d ", n - minDist);
//         }
//         printf("\n");
//     }

//     return 0;
// }