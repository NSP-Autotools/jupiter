#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void * print_it(void * data)
{
    printf("Hello from %s!\n", (const char *)data);
    return 0;
}

int main(int argc, char * argv[])
{
    pthread_t tid;
    pthread_create(&tid, 0, print_it, argv[0]);
    pthread_join(tid, 0);
    return 0;
}
