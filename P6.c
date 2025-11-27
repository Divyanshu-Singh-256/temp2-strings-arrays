//WAP to take 10 values from the user and store them in an array name numbers. Print the elements stored in the array.
#include <stdio.h>
#define SIZE 10
int main() {
    int numbers[SIZE];
    printf("Enter %d integers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("The elements in the array are:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}