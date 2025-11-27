// Write a C program to demonstrate basic string operations such as copying one string to another, concatenating strings with spaces, finding the length of strings, and comparing two strings using string functions like strcpy(), strcat(), strlen(), and strcmp(). Print the results of concatenation, length, and string comparison.
#include <stdio.h>
#include <string.h>
int main() {
    char str1[100], str2[100], result[200];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    // Copying string
    strcpy(result, str1);
    printf("Copied string: %s\n", result);
    // Concatenating strings
    strcat(result, " ");
    strcat(result, str2);
    printf("Concatenated string: %s\n", result);
    // Finding length of strings
    printf("Length of first string: %lu\n", strlen(str1));
    printf("Length of second string: %lu\n", strlen(str2));
    // Comparing strings
    int cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal.\n");
    } else if (cmp < 0) {
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }

    return 0;
}