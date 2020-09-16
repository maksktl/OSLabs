#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
    int *id = (int *) arg;
    printf("Hello from thread #%d\n", *id);
    pthread_exit(NULL);
}

int main() {
    for (int i = 0; i < 8; i++) {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, &i);
        printf("Thread#%d created\n", i);
        pthread_join(tid, NULL);
    }
    return 0;
}