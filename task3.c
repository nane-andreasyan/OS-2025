#include <stdio.h> 
#include <stdlib.h>

void afterExit1(void){
    printf ("First atexit() succeeded!\n");
}

void afterExit2(void){
    printf ("Second atexit() succeeded!\n");
}

int main() 
{ 
    int a = 8;
    if (atexit(afterExit1)) {
        perror("atexit1");
    }

    if (atexit(afterExit2)) {
        perror("atexit2");
    }
    if(a<10){
        printf("a is less than 10\n");
        exit(0);
    }
 
    printf("a is not less than 10\n");
    exit(0);

} 
