// #include<stdio.h>
// int main(){
//     // int arr[2][2];
//     // arr[0][0]=12;
//     // arr[0][1]=13;
//     // arr[1][0]=14;
//     // arr[1][1]=15;
//     // printf("%d",arr[0][0]);
     
//     int arr[2][2]={{1,2},{3,4}};
//     printf("%d",arr[0][1]);
//     return 0;
// }








//wap to store roll number and marks obtained by 4 students side by side in a matrix

// #include<stdio.h>
// int main(){
// int arr[4][2] ={{76,80},{57,81},{40,90},{21,95}};
// printf(" the ragahav marks and roll number  is %d",arr[1][1]);
//     return 0;
// }




//user input 
#include <stdio.h>
int main() {
    int arr[4][2];   // 4 students, 2 values each (roll no, marks)

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0)
                printf("Enter roll number for student %d: ", i+1);
            else
                printf("Enter marks for student %d: ", i+1);

            scanf("%d", &arr[i][j]);  //  store in array
        }
    }

    // Example: print roll number and marks of student 2
    printf("\nStudent 2 -> Roll: %d, Marks: %d\n", arr[1][0], arr[1][1]);

    return 0;
}