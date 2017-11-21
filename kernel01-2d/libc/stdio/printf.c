#include <limits.h>
#include <stdbool.h>//c does not have booleans by default
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static bool print(const char* data, size_t length){
    const unsigned char* bytes = (const unsigned char*) data;
        for(size_t i=0;i<length;i++){
            if(putchar(bytes[i])==EOF){
                return false;
            }
        }
        return true;
}

int printf(const char* restrict format, ...){
    va_list parameters;
    va_start(parameters, format);

    int written=0;
    while(*format!='\0'){
        size_t maxrem = INT_MAX - written;

        if(format[0] != '%' || format[1] == '%'){
            if(format[0] == '%'){
                format++;
            }//end if brace
            size_t amount = 1;
            while(format[amount] && format[amount] != '%'){
                amount++;
            }//end while
            if(maxrem < amount){
                //TO-DO: set errno to EOVERFLOW
                return -1;
            }//end if
            if(!print(format, amount)){
                return -1;
            }//end if
            format+=amount;
            written+=amount;
            continue;
        }//end first if

    const char* format_begun_at = format++;

    if(*format=='c'){
        format++;
        char c = (char) va_arg(parameters, int /*char is changed to int*/);
        if(!maxrem){
            return -1;
        }//end if
        if(!print(&c, sizeof(c))){
            return -1;
        }//end if
        written++;
    }else if (*format=='s'){
        format++;
        const char* str = va_arg(parameters, const char*);
        size_t len = strlen(str);
        if (maxrem < len){
            //TO-DO: set errno to EOVERFLOW
            return -1;
        }//end if
        if(!print(str, len)){
            return -1;
        }//end if
        written += len;
    }else{
        format = format_begun_at;
        size_t len = strlen(format);
        if (maxrem < len){
            return -1;
        }//end if
        if(!print(format, len)){
            return -1;
        }//end if
        written+=len;
        format+=len;
    }//end second if
    va_end(parameters);
    return written;
}//end while
}//end printf
