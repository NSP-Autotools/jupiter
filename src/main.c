#include "config.h"

#include "libjupiter.h"
#include "module.h"

#if HAVE_LTDL_H
# include <ltdl.h>
#endif

#define DEFAULT_SALUTATION "Hello"

int main(int argc, char * argv[])
{
    int rv;
    const char * salutation = DEFAULT_SALUTATION;

#if HAVE_LTDL_H
    int ltdl;
    lt_dlhandle module;
    get_salutation_t * get_salutation_fp = 0;

    LTDL_SET_PRELOADED_SYMBOLS();

    ltdl = lt_dlinit();
    if (ltdl == 0)
    {
        module = lt_dlopen("modules/hithere/hithere.la");
        if (module != 0)
        {
            get_salutation_fp = (get_salutation_t *)lt_dlsym(module, GET_SALUTATION_SYM);
            if (get_salutation_fp != 0)
                salutation = get_salutation_fp();
        }
    }
#endif

    rv = jupiter_print(salutation, argv[0]);

#if HAVE_LTDL_H
    if (ltdl == 0)
    {
        if (module != 0)
            lt_dlclose(module);
        lt_dlexit();
    }
#endif

    return rv;
}
