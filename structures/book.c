// create a structures type "book" with name , price and number of pages as it attributes

#include<stdio.h>
#include<string.h>
int main(){
    struct book{
      char name[50];
      int noofpages;
      float price;
    }a,b,c;

     strcpy(a.name," secret seven ");
     a.price =413.34;
     a.noofpages=100;

     strcpy(b.name," famous five  ");
     b.price =234.34;
     b.noofpages=200;
    
      printf("%s\n",a.name);
        printf("%d\n",a.noofpages);
            printf("%f\n",a.price);

                printf("%s\n",b.name);
                printf("%d\n",b.noofpages);
                printf("%f\n",b.price);
    return 0;
}