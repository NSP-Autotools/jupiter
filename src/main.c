#include "config.h"

#include "libjupiter.h"
#include "module.h"

#if HAVE_DLFCN_H
# include <dlfcn.h>
#endif

#define DEFAULT_SALUTATION "Hello"

int main(int argc, char * argv[])
{
    int rv;
    const char * salutation = DEFAULT_SALUTATION;

#if HAVE_DLFCN_H
    void * module;
    get_salutation_t * get_salutation_fp = 0;
    module = dlopen("./module.so", RTLD_NOW);
    if (module != 0)
    {
        get_salutation_fp = (get_salutation_t *)dlsym(module, GET_SALUTATION_SYM);
        if (get_salutation_fp != 0)
            salutation = get_salutation_fp();
    }
#endif

    rv = jupiter_print(salutation, argv[0]);

#if HAVE_DLFCN_H
    if (module != 0)
        dlclose(module);
#endif

    return rv;
}
