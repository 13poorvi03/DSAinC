//create a structure type "person" with name , salary and age as its attribute declare and intialize 2 variable for this . print the name of first person and age of the other 

#include <stdio.h>

// Define structure type "person"
struct person {
    char name[50];
    float salary;
    int age;
};

int main() {
    // Declare and initialize two variables of type "person"
    struct person p1 = {"Alice", 50000.0, 25};
    struct person p2 = {"Bob", 60000.0, 30};

    // Print the name of the first person
    printf("Name of first person: %s\n", p1.name);

    // Print the age of the second person
    printf("Age of second person: %d\n", p2.age);

    return 0;
}