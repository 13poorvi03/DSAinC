#include <stdio.h>
int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 2, 1};  // example palindrome array

    int isPalindrome = 1;  // assume true

    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            isPalindrome = 0;  // mismatch found
            break;
        }
    }

    if (isPalindrome) {
        printf("This array is a palindrome\n");
    } else {
        printf("This array is not a palindrome\n");
    }

    return 0;
}