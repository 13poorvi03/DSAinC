// && multiple pointer declaration problem 

#include<stdio.h>
typedef int* pointer;

int main(){
    int x= 5, y=8;
    pointer a = &x, b= &y;
    // int* a,b;           // int* x and int y it means ek pointer a bna h and ek variable b bana h 
    printf("%p\n",a);
    printf("%p\n",b);
}