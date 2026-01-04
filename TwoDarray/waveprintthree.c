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

     for(int j=0; j<c; j++){
      if(j%2==0){
      for(int i =0; i<r; i++){
       printf("%d ",arr[i][j]);
      }
     }
      else{
        for(int i=r-1; i>=0; i--){
       printf("%d ",arr[i][j]);
        }
      }
        printf("\n");
     }
     return 0;
}