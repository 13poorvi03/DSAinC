
// you have to print this pattern
//  * 
//  *  *
//  *  *  *
//  *  *  *  *
//  *  *  *  *  *

// j prints star and basically row = stars print so that's why each line have same count of start equals to row
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

    return 0;
}