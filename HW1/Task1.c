#include <stdio.h>

int main()
{
    int var = 3;
    int *ptr = &var;
    printf("Address of integer variable from variable: %p\n", &var);
    printf("Address of integer variable from pointer: %p\n", ptr);
    printf("Old value of variable: %d\n", var);
    *ptr =10;
    printf("New value of variable: %d\n", *ptr);

}
