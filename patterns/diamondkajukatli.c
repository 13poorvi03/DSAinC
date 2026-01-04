

#include <stdio.h>
int main() {
    int n;
    printf("Enter size of kaju katli (half height): ");
    scanf("%d", &n);

    // Upper half of diamond
    for (int i = 1; i <= n; i++) {
        // spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // stars
        for (int j = 1; j <= (2*i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of diamond
    for (int i = n-1; i >= 1; i--) {
        // spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        // stars
        for (int j = 1; j <= (2*i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}





// #include <stdio.h>
// int main() {
//     int n;
//     printf("Enter size of kaju katli (half height): ");
//     scanf("%d", &n);

//     // Upper half of diamond
//     for (int i = 1; i <= n; i++) {
//         // spaces
//         for (int j = i; j < n; j++) {
//             printf(" ");
//         }
//         // stars
//         for (int j = 1; j <= (2*i - 1); j++) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     // Lower half of diamond
//     for (int i = n-1; i >= 1; i--) {
//         // spaces
//         for (int j = i; j < n; j++) {
//             printf(" ");
//         }
//         // stars
//         for (int j = 1; j <= (2*i - 1); j++) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }