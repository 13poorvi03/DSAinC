//wap to store 10 at every index of a 2D matrix with 5 rows and 5 columns

// #include<stdio.h>
// int main(){
//  int arr[5][5];
//  for(int i=0; i<5; i++){
//     for(int j=0; j<5; j++){
//         scanf("%d",&arr[i][j]);
//     }
//  }  
//    printf("\n");
//   for(int i=0; i<5; i++){
//     for(int j=0; j<5; j++){
//         printf("%d ", arr[i][j]);
//     }
//     printf("\n");
//  }   
   
//     return 0;
// }




#include <stdio.h>
int main() {
    int arr[5][5];
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);   

    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){ 
            arr[i][j] = num;           // fill every elem with same number 
        }
    }

    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            printf("%d ", arr[i][j]);  // print the matrix 
        }
        printf("\n");
    }

    return 0;
}