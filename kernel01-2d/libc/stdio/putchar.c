#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif // defined

int putchar(int ic){
#if defined(__is_libk)
    char c = (char) ic;
    term_write(&c, sizeof(c));
#else
    //TODO - implement stdio and the system write call
#endif // defined
    return ic;
}
