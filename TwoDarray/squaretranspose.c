//wap to change the given matrix n*n matrix to its transpose

#include <stdio.h>

// in this u have to make extra variable and use swappping logic 

int main() {
   int n;
   printf("enter the number : ");
   scanf("%d",&n);
   int arr[n][n];          // (n*n)
    //input
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        scanf("%d", &arr[i][j]);
    }
   }
   // transpose
     for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp =arr[i][j];
            arr[i][j]= arr[j][i];
            arr[j][i]= temp;
        }
     }
        //output
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf(" %d ",arr[i][j]);
        }
        printf("\n");
      }
    return 0;
}
