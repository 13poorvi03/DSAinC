#include <stdio.h>
int main() {
    int arr[6] = {2, 5, 3, 4, 6, 7};
    int max = arr[0];
    int smax = -1;  // or INT_MIN if <limits.h> is included

    for (int i = 1; i < 6; i++) {
        if (arr[i] > max) {
            smax = max;   // old max becomes second max
            max = arr[i]; // update max
        } else if (arr[i] > smax && arr[i] != max) {
            smax = arr[i]; // update second max
        }
    }

    printf("max : %d\n", max);
    printf("second largest : %d\n", smax);

    return 0;
}