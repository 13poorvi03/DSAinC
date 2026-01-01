#include<stdio.h>
int main(){
    int a= 25;
    int* x = &a;
    // pointer ki help se hum kisi dusri cheez jiska humare pass bass address h wha ki value ko change kr sakte h  
    *x =7;    //the value of a is changed 

    printf("%d\n",a);

    return 0;
}