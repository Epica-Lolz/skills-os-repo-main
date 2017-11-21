#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

__attribute__((__noreturn__));
void abort(void);//calling abort function for use in other .c files

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STDLIB_H

