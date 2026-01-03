//wap to roatate a matrix 90 degree clockwise ---leetcode- 48 
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    int arr[n][n];   // (n*n)

    // Input
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    // Transpose
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // Reverse each row (to rotate 90° clockwise)
    for(int i=0; i<n; i++){
        int j=0, k=n-1;
        while(j < k){
            int temp = arr[i][j];
            arr[i][j] = arr[i][k];
            arr[i][k] = temp;
            j++;
            k--;
        }
    }

    // Output
    printf("\nRotated Matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}