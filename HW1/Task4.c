#include <stdio.h>

int main() {

    int var = 10;
    int *ptr = &var;
    int **doubleptr = &ptr;

    printf("Value using pointer: %d\n", *ptr);
    printf("Value using double pointer: %d\n", **doubleptr);
    
}