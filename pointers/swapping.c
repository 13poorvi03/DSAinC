// pass by reference 
#include<stdio.h>

// *x means  pointer x pr jao and uspar jo variable "a" ki value store ho rakhi h usko temp pr lejakra store kardo 
// then *y pr jo variable "b" ki value daali h usko forcefully *x par store kardo jise variable "a" ki value change ho jayegi 
// *y pr jao then uss pr forceflly temp ki value store kardo jisse variable "b" ki value cchange ho jayegi 
// then swapping done 
void swap(int* x, int* y){    ///int*x is holding address of "a" //int*y is holding address of "b"
    int temp ;
    temp =*x; // temp =2
    *x = *y;  // a= 9                //*x is pointing "a" so they stored a variable value so we changed value of "a" directly with help of pointers
    *y = temp; // y =2                    //*y is pointing to "b" so now we changed value of a = b
    return ;
}
int main(){
    int a = 2; 
    int b = 9; 

    swap(&a,&b);

    // int*x = &a;
    // int*y = &b;
    // swap(x,y);

    printf("the value of a is %d\n",a);

    printf("the value of b is %d\n",b);

    return 0;
}