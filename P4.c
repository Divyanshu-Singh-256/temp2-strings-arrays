//WAP to read a list of integers and store it in a single dimensional array. Write a C program to find the frequency of a particular number in a list of integers.
#include <stdio.h>
int main() {
    int n, i, number, frequency = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to find its frequency: ");
    scanf("%d", &number);
    for (i = 0; i < n; i++) {
        if (arr[i] == number) {
            frequency++;
        }
    }
    printf("The frequency of %d in the array is: %d\n", number, frequency);
    return 0;
}