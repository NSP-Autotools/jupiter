#define printf mock_printf
#include "print.c"

#include <stdarg.h>
#include <string.h>

static char printf_buf[512];

int mock_printf(const char * format, ... )
{
    int rc;
    va_list ap;
    va_start(ap, format);
    rc = vsnprintf(printf_buf, sizeof printf_buf, format, ap);
    va_end(ap);
    return rc;
}

int main(void)
{
    const char *args[] = { "Hello", "test" };
    int rc = print_it(args);
    return rc != 0 || strcmp(printf_buf, "Hello from test!\n") != 0;
}
