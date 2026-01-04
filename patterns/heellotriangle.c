#include<stdio.h>
int main(){
    int n;
    printf("enter the number of rows : ");
    scanf("%d",&n);


    for(int i=0; i<n; i++){// for space // for rows
        for(int j=0; j<=i; j++){ // for star // for columns
               printf(" * ");
        }
                  printf("\n");
    }
   
        for(int k=0; k<n; k++){  // for next line 
        for(int m=k+1; m<n; m++){ //for stars
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}
