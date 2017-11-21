#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))//states that the function (presumably 'abort()') does not return a value.
void abort(void){//definition of abort() function
#if defined(__is_libk)
    printf("kernel: panic: abort()\n"); //basically a kernel panic
#else
    printf("abort()\n"); //basically terminate entire operating system process. riparoni
#endif // defined
    while(1){} //basically a loop xD
    __builtin_unreachable();//tells gcc that it is the end of a function.
}
