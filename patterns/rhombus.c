#include <stdio.h>
int main() {
    int n;
    printf("Enter size of rhombus: ");
    scanf("%d", &n);

    // print rhombus
    for (int i = 0; i < n; i++) {
        // print leading spaces
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // print stars
        for (int j = 0; j < n; j++) {
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}