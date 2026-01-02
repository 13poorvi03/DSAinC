// find the sum of a given matrices of n*m
//n = rows
//m =coloumns

#include<stdio.h>
int main(){
    int n, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int arr[n][m];   // Variable length array
    int sum = 0;

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);   
        }
    }

    //  sum
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum += arr[i][j];
        }
    }

    // Print
    printf("The total sum of elements: %d\n", sum);

    return 0;
}