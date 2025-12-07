#include <pthread.h>
#include <stdio.h>

void* worker(void* arg) {
    printf("Hello from thread! Argument: %d\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t thread;
    int value = 42;

    pthread_create(&thread, NULL, worker, &value);
    pthread_join(thread, NULL);

    return 0;
}
