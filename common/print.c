#include "config.h"

#include "jupcommon.h"

#include <stdio.h>
#include <stdlib.h>

#if HAVE_PTHREAD_H
# include <pthread.h>
#endif

static void * print_it(void * data)
{
    printf("Hello from %s!\n", (const char *)data);
    return 0;
}

int print_routine(const char * name)
{
#if ASYNC_EXEC
    pthread_t tid;
    pthread_create(&tid, 0, print_it, (void *)name);
    pthread_join(tid, 0);
#else
    print_it(name);
#endif
    return 0;
}
