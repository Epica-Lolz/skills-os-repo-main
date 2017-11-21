#include <stdio.h>

int puts(const char* string){//puts() function implemented from stdio.h from regular c library
    return printf("%s\n", string);//%s tells printf() that it is a string you are inputting, and \n is of course newline.
}
