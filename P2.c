//WAP  to find the average of n = 40 numbers using arrays. Convert the type of array using type conversion.
#include <stdio.h>
int main() {
    int n = 40;
    int numbers[40];
    float sum = 0.0, average;
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i]; 
    }
    average = sum / n; 
    average = (float)sum / n;
    printf("The average of the entered numbers is: %.2f\n", average);

    return 0;
}