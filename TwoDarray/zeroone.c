// given a matrix having 0-1 only , find the eow with the maximum number of 1's

#include<stdio.h>
int main(){
    int arr[3][4]={{1,0,1,1},{0,1,1,0},{1,1,1,1}};
    // 1 0 1 1
    // 0 1 1 0
    // 1 1 1 1
    int maxCount =0;
    int maxIdx = -1;
    for(int i =0; i<3; i++){
        int count = 0;              //yeh count hr baar store hoga 
        for(int j=0; j<4; j++){
           if(arr[i][j]==1) count++;    // if arr[i][j] 1 ke equal h toa count ko bada do 
        }
        if(maxCount<count){    //agr maxcount chota h count se toa usse maxcount mae store kardo
            maxCount =count;
            maxIdx = i;
        }
        printf("\n");
        
    }
    printf(" the row of matrices : %d\n",maxIdx);
    printf("the total Maxcount of one in row %d : ",maxCount);
    return 0;
}