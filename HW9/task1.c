#include <pthread.h>
#include <stdio.h>

void* print_message(void* arg) {
    pthread_t id = pthread_self();
    printf("Thread %lu is running\n", (unsigned long)id);
    return NULL;
}

int main() {

    pthread_t t1, t2, t3;
    int ret;
    ret = pthread_create(&t1, NULL, print_message, NULL);
    if (ret != 0) {
        perror("failed to create thread 1");
        return 1;
    }
    ret = pthread_create(&t2, NULL, print_message, NULL);
    if (ret != 0) {
        perror("failed to create thread 2");
        return 1;
    }
    ret = pthread_create(&t3, NULL, print_message, NULL);
    if (ret != 0) {
        perror("failed to create thread 3");
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

    return 0;
}
