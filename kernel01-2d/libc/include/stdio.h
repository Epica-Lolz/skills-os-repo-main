#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int printf(const char* __restrict, ...);
int putchar(int);
int puts(const char*);
char *gets(char *str, char in);
char getchar(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _STDIO_H
