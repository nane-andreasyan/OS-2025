#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int *ptr = &arr[0];
    for(int i = 0; i<5; i++) {
        printf("Element %d: %d\n", i, *(ptr+i));
    }

    printf("\n");

    for(int i = 0; i<5; i++) {
        *(arr+i) = *(ptr+i)+1;
    }

    for(int i = 0; i<5; i++) {
        printf("New Element %d: %d\n", i, *(ptr+i));
    }

    printf("\n");

    for(int i = 0; i<5; i++) {
        printf("New Element %d using array name: %d\n", i, arr[i]);
    }


}