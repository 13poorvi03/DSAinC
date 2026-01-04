
// given array - 9 1 3 4 10 5 6

//u have to make it - 1 3 4 6 5 6 9 10


/// sorting -- is to arrange the array elem in asscending order 

#include<stdio.h>
int main(){
    int arr[7]={9,1,3,4,10,5,6};
    
    for(int i=0; i<7; i++){
        for(int j=i+1;j<7;j++){
         if(arr[i]>arr[j]){
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
          
        }
    }
    for(int k=0 ; k<7 ; k++){
        
        printf("%d ",arr[k]);
  
  }
    return 0;
}





// ///  arrange the array elem in desscending order 

// #include<stdio.h>
// int main(){
//     int arr[7]={9,1,3,4,10,5,6};
    
//     for(int i=0; i<7; i++){
//         for(int j=i+1;j<7;j++){
//          if(arr[i]<arr[j]){
//             int temp =arr[i];
//             arr[i]=arr[j];
//             arr[j]=temp;
//          }
          
//         }
//     }
//     for(int i=0 ; i<7 ; i++){
        
//         printf("%d ",arr[i]);
  
//   }
//     return 0;
// }

