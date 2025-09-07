#include <stdio.h>

int main(){
    char str[] = "Hello";
    char *ptr = &str[0];
    char *count = &str[0];

    while(*ptr != '\0') {
        printf("%c", *(ptr));
        ptr++;
    }
    printf("\n");

    int length = ptr - count; 

    printf("Length of string: %d\n", length);
}