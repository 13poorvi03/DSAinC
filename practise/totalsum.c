#include<stdio.h>
int main(){
   
    int arr[6]={2,5,3,4,6,7};
     int sum =7;
     int pairs=0;
     for(int i=0; i<6; i++){
        for(int j=i+1; j<6;j++){
            if(arr[i]+arr[j]==sum){
                pairs++;
            }
        }
     }
     printf("total pairs %d : ",pairs);
    return  0;
}