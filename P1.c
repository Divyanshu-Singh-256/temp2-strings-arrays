//Using standard library functions of string
//Define user-defined functions for copy, length, concatenation and string comparison. 
#include <stdio.h>
#include <string.h>
void copyString(char* source, char* destination) {
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0'; 
}
int stringLength(char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
void concatenateStrings(char* str1, char* str2, char* result) {
    while (*str1 != '\0') {
        *result = *str1;
        str1++;
        result++;
    }
    while (*str2 != '\0') {
        *result = *str2;
        str2++;
        result++;
    }
    *result = '\0';
}
int compareStrings(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2); 
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}
int main() {
    char str1[100], str2[100], result[200];
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    char copy[100];
    copyString(str1, copy);
    printf("Copied string: %s\n", copy);
    int len = stringLength(str1);
    printf("Length of first string: %d\n", len);
    concatenateStrings(str1, str2, result);
    printf("Concatenated string: %s\n", result);
    int cmp = compareStrings(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal.\n");
    } else if (cmp < 0) {
        printf("First string is less than second string.\n");
    } else {
        printf("First string is greater than second string.\n");
    }
    return 0;
}