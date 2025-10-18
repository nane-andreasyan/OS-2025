#include <stdio.h>

int main() {

    int num;
    char c;
    double d;
    short s;

    printf("Size of int: %zu bytes\n", sizeof(num));
    printf("Size of char: %zu bytes\n", sizeof(c));
    printf("Size of double: %zu bytes\n", sizeof(d));
    printf("Size of short: %zu bytes\n", sizeof(s));

    printf("Address of int variable: %p\n", &num);
    printf("Address of char variable: %p\n", &c);
    printf("Address of double variable: %p\n", &d);
    printf("Address of short variable: %p\n", &s);


}

