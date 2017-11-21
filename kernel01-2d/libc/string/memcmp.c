#include <string.h>
//compares two blocks of memory
int memcmp(const void* aptr/*aptr is first block of memory*/, const void* bptr/*ptr2 is second block of memory*/, size_t size/*size is the number of bytes each block takes up*/){
    const unsigned char* a = (const unsigned char*) aptr;//setting local variable 'a' to read-only unsigned char pointer array 'aptr'.
    const unsigned char* b = (const unsigned char*) bptr;//setting local variable 'b' to read-only unsigned char pointer array 'bptr'.
    for (size_t i=0;i<size;i++){//i is another index variable that gradually incremented to the size of 'size'.
        if(a[i]<b[i]){//if the size of block 'a' is less than the size of block 'b', return -1.
            return -1;//return -1 to the file using this function. dont return this entire file as an error.
        }else if(b[i]<a[i]){//if the size of block 'b' is less than the size of block 'a', return 1.
            return 1;//return 1 to the file using this function. dont return this entire file as an error.
        }
    }
    return 0;//ah there we go. a nice return statement that says the function returned error-free and without issues.
}
