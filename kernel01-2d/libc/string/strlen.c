#include <string.h>
//finds the number of characters in a string.

size_t strlen(const char* str){//const char* str is the string being put into the function
    size_t len=0;//variable that represents length. set to 0, but it acts as an index. idk why this wasn't implemented as a for loop.
    while(str[len]){//while string still has a character in it (don't forget, 'len' acts as an index and goes through each character in the string one at a time.).
        len++;//increment 'len' to represent the next character in the string.
    }
    return len;//return the total number of characters in the string
}
