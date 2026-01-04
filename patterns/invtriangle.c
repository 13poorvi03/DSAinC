#include<stdio.h>
int main(){
    int n;
    printf("enter the number of rows : ");
    scanf("%d",&n);


    for(int i=n-1; i>=0; i--){// for space // for rows
        for(int j=0; j<=i; j++){ // for star // for columns
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}

/// in this we use row n-1 coz we print row = stars 