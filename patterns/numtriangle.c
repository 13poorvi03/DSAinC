// #include<stdio.h>
// int main(){
//     int n;
//     printf("enter the number of rows : ");
//     scanf("%d",&n);


//     for(int i=n-1; i>=0; i--){// for space // for rows
//         for(int j=1; j<=i; j++){ // for star // for columns
//             printf(" %d ",j);
//         }
//         printf("\n");
//     }

//     return 0;
// }



#include<stdio.h>
int main(){
    int n;
    printf("enter the number of rows : ");
    scanf("%d",&n);


    for(int i=n-1; i>=0; i--){// for space // for rows
        for(int j=1; j<=i; j++){ // for star // for columns
            printf(" %d ",i);
        }
        printf("\n");
    }

    return 0;
}
