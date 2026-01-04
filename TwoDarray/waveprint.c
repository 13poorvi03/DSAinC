//wave print 

// 1 2 3
// 4 5 6
// 7 8 9

//you have to print in order of s basically number should be aligned in 1 2 3 6 5 4 7 8 9
// first row is in left to right 
// second row is in right to left 
// third row is in left to right 

#include<stdio.h>
int main(){
   int r,c;
   printf("enter the number of row : ");
   scanf("%d",&r);
   printf("enter the number of columns : ");
   scanf("%d",&c);
   
   int arr[r][c];
   
   for(int i=0; i<r; i++){
     for(int j =0; j<c; j++){
      scanf("%d",&arr[i][j]);
      }
   }
   
       printf("\n");

     //wave print

     for(int i=0; i<r; i++){
      if(i%2==0){
      for(int j =0; j<c; j++){
       printf("%d ",arr[i][j]);
      }
     }
      else{
        for(int j =c-1; j>=0; j--){
       printf("%d ",arr[i][j]);
        }
      }
        printf("\n");
     }
     return 0;
}