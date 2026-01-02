// find the minimum element

#include<stdio.h>
#include<limits.h>
int main(){
    int n, m;
    int min =INT_MAX;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int arr[n][m];   // Variable length array

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);   
        }
    }

    //  max
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           if(min>arr[i][j]){
              min = arr[i][j];
           }
        }
    }

    // Print
    printf("The maximum of elements: %d\n", min);

    return 0;
}