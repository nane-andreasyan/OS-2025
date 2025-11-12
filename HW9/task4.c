#include <pthread.h>
#include <stdio.h>


void* square(void* arg) {
    int num = *(int*) arg;
    printf("Square of %d is %d\n", num, num*num);
    return NULL;
}


int main(){
    int arr[5];

    for(int i=0;i<5;i++){
        arr[i]=i+1;
    }

    pthread_t t1, t2, t3, t4, t5;
    int ret;

    ret = pthread_create(&t1, NULL, square, (void *)(&arr[0]));
    if(ret !=0 ){
        perror("failed to create thread 1");
        return 1;
    }
    ret = pthread_create(&t2, NULL, square, (void *)(&arr[1]));
    if(ret !=0 ){
        perror("failed to create thread 2");
        return 1;

    }
    ret = pthread_create(&t3, NULL, square, (void *)(&arr[2]));
      if(ret !=0 ){
        perror("failed to create thread 3");
        return 1;

    }
    ret = pthread_create(&t4, NULL, square, (void *)(&arr[3]));
      if(ret !=0 ){
        perror("failed to create thread 4");
        return 1;

    }
    ret = pthread_create(&t5, NULL, square, (void *)(&arr[4]));
      if(ret !=0 ){
        perror("failed to create thread 5");
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

    if (pthread_join(t3, NULL) != 0) {
        perror("Failed to join thread 3");
        return 1;
    }

    if (pthread_join(t4, NULL) != 0) {
        perror("Failed to join thread 4");
        return 1;
    }

    if (pthread_join(t5, NULL) != 0) {
        perror("Failed to join thread 5");
        return 1;
    }

    return 0;

}
