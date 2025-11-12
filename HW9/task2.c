#include <pthread.h>
#include <stdio.h>

void* sum(void* arg) {
    int *arr = (int *)arg;
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += arr[i];
    }
    printf("Sum: %d\n", total);
    return NULL;
}

int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i]=i;
    }

    int first_half[5];
    int second_half[5];
    for(int i=0;i<5;i++){
        first_half[i]=arr[i];
        second_half[i]=arr[i+5];
    }

    pthread_t t1, t2;
    int ret;
    ret = pthread_create(&t1, NULL, sum, (void *)(first_half));
    if(ret !=0 ){
        perror("failed to create thread 1");
        return 1;
    }

    ret = pthread_create(&t2, NULL, sum, (void *)(second_half));
    if(ret !=0 ){
        perror("failed to create thread 1");
        return 1;
    }

   if (pthread_join(t1, NULL) != 0) {
        perror("Failed to join thread 1");
        return 1;
    }

    if (pthread_join(t2, NULL) != 0) {
        perror("Failed to join thread 2");
        return 1;
    }
    return 0;

}
