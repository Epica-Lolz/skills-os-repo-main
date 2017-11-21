#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>


void term_init(void);//call the term_init() function for use in other .c files
void term_putchar(char c);//call the term_putchar() function for use in other .c files
void term_write(const char* data, size_t _size);//call the term_write() function for use in other .c files
void term_writestring(const char* data);//call the term_writestring() function for use in other .c files
void term_scroll();

#endif // _KERNEL_TTY_H
