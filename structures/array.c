/// a reacord contains name of cricketer his age number of test maches that he has played and the average runs that to hold records of 20 such cricketer and then wap to read these records

#include <stdio.h>

// Structure to hold cricketer details
struct Cricketer {
    char name[50];   // Cricketer ka naam
    int age;         // Cricketer ki age
    int testMatches; // Number of test matches played
    float avgRuns;   // Average runs
};

int main() {
    struct Cricketer cr[20];  // Array of 20 cricketers
    int i;

    // Input records
    printf("Enter details of 20 cricketers:\n");
    for (i = 0; i < 20; i++) {
        printf("\nCricketer %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", cr[i].name);  // String input (single word names)
        printf("Age: ");
        scanf("%d", &cr[i].age);
        printf("Number of Test Matches: ");
        scanf("%d", &cr[i].testMatches);
        printf("Average Runs: ");
        scanf("%f", &cr[i].avgRuns);
    }

    // Output records
    printf("\n--- Cricketer Records ---\n");
    for (i = 0; i < 20; i++) {
        printf("\nCricketer %d:\n", i + 1);
        printf("Name: %s\n", cr[i].name);
        printf("Age: %d\n", cr[i].age);
        printf("Test Matches: %d\n", cr[i].testMatches);
        printf("Average Runs: %.2f\n", cr[i].avgRuns);
    }

    return 0;
}