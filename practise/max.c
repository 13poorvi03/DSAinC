#include<stdio.h>
int main(){
    int arr[5]={23,45,67,89,4};
    int max=0;
    for(int i=0; i<5; i++){
            if(max<arr[i]){
                max =arr[i];
            
        }
    }
    printf("maximum num %d: ",max);
    return 0;
}