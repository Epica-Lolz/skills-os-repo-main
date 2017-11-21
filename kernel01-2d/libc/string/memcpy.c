#include <string.h>
//copies source memory block data to the destination memory block

void* memcpy(void* restrict/*restrict is used to let the compiler know that this pointer does not point to any other areas in memory.*/ dstptr/*destination pointer*/, const void* restrict srcptr/*source pointer*/, size_t size/*size of block in bytes*/){
    unsigned char* dst = (unsigned char*) dstptr;//local 'dst' is now (unsigned char*) dstptr
    const unsigned char* src = (const unsigned char*) srcptr;//local 'src' pointer is now (const unsigned char*) srcptr
    for(size_t i=0;i<size;i++){//i is an index variable that goes through 'size' and is incremented by 1.
        dst[i]=src[i];// src[i] is copying every last bit of data to dst[i].
    }
    return dstptr;//return the destination pointer
}
