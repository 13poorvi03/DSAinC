// #include<stdio.h>
// typedef float realnumber;
// int main(){
//    int x = 23;
//    realnumber y =123.56; 
//    printf("%d\n",x);
//    printf("%f",y);
//     return 0;
// }



#include<stdio.h>
#include<string.h>

int main() {
    typedef struct Book {
        char name[50];
        int noofpages;
        float price;
    } Book;

    Book a = {"C Programming", 350, 299.99};
    Book b = {"Data Structures", 500, 399.50};

    printf("Book A: %s, Pages: %d, Price: %.2f\n", a.name, a.noofpages, a.price);
    printf("Book B: %s, Pages: %d, Price: %.2f\n", b.name, b.noofpages, b.price);

    return 0;
}