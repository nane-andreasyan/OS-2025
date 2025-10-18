#include <stdio.h>

    struct data_1 {
        char a;
        int b;
        double c;
    };
    
    #pragma pack(1)
    struct data_2 {
        char a;
        int b;
        double c;
    };

    #pragma pack(4)
    struct data_3 {
        char a;
        int b;
        double c;
    };


int main() {

    struct data_1 data_1;
    struct data_2 data_2;
    struct data_3 data_3;


    printf("Struct 1: no pragma pack\n");
    printf("Size of struct 1: %zu bytes\n", sizeof(data_1));
    printf("Address of char: %p\n", &data_1.a);
    printf("Address of int: %p\n", &data_1.b);
    printf("Address of double: %p\n\n", &data_1.c);

    printf("Struct 2: pragma pack(1)\n");
    printf("Size of struct 2: %zu bytes\n", sizeof(data_2));
    printf("Address of char: %p\n", &data_2.a);
    printf("Address of int: %p\n", &data_2.b);
    printf("Address of double: %p\n\n", &data_2.c);

    printf("Struct 3: pragma pack(4)\n");
    printf("Size of struct 3: %zu bytes\n", sizeof(data_3));
    printf("Address of char: %p\n", &data_3.a);
    printf("Address of int: %p\n", &data_3.b);
    printf("Address of double: %p\n\n", &data_3.c);

}
