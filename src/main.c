#include "config.h"

#include "libjupiter.h"

#define DEFAULT_SALUTATION "Hello"

int main(int argc, char * argv[])
{
    const char * salutation = DEFAULT_SALUTATION;
    return jupiter_print(salutation, argv[0]);
}
