#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b =  *a;
    *a = temp;
}

int main() {
    int a = 3;
    int b = 4;

    printf("Values before swap: %d, %d\n", a, b);
    swap(&a,&b);
    printf("Values after swap: %d, %d\n", a, b);

}


