// pass by reference 
#include<stdio.h>
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