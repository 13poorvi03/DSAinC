#include<stdio.h>
int main(){
    int a = 25;
    int* x= &a;   /// int* -> int ka address store karta
    int** y= &x;  ///int** -> int* ka address store karte h
     printf("%d\n",*x);      // this print value of variable "a", which is store in pointer "x"  
     printf("%p\n",y);         // %p se address print hota h
     printf("%d\n",**y);     ///this store value of x* so this will print value of variable "a"
     return 0;
}