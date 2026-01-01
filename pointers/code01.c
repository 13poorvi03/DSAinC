//"%d"-integer
//%c-char
//%f- float
//%p-address
#include<stdio.h>
int main(){
    int a =5;
    int* x =&a; //yeh alg dabba h jo address store kar rha h 

    //this is the one style to write 
    
    //int* x;
    //x = &a;

    // printf("%p\n",x);      // x is the pointer and it give adress of elem 'a' // %p se adress print hota h 
    // printf("%p\n",&x);       //&x iss x pointer address
   
   printf("%d",*x) ;   //thse meaning of * is x ke andar jis bhi variable ka address store h uss variable ko point karo and uske andar jo bhi pada h sse print kardo 
    return 0;
}