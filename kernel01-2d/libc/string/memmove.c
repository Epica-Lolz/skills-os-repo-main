#include <string.h>
//moves (or technically just copies) data from one location in memory to the next.

//declared pointers as void because the data can range from characters to integers to floating point numbers, etc...
void* memmove(void* dstptr/*destination in memory pointer*/, const void* srcptr/*read only pointer that represents data (the "source" you are moving to the destination)*/, size_t size){
    unsigned char* dst = (unsigned char*) dstptr;//setting unsigned char destination (or 'dst' in this case) to the void pointer 'dstptr', typecasted as an unsigned char pointer array.
    const unsigned char* src = (const unsigned char*) srcptr;//basically the same thing, but with the source pointer. because it is a constant, I am typecasting it as a constant unsigned char pointer array since the data source is read-only.
    if (dst < src){ //if the destination is empty and the source has the data
        for (size_t i=0;i<size;i++){
            dst[i] = src[i];//setting the destination of the memory to the source; essentially copying the data over to the destination.
        }
    }else{
        for (size_t i=size;i!=0;i--){//document here :3
            dst[i-1]=src[i-1];
        }
    }
    return dstptr;//return the destination pointer, which should now contain the data copied from the source.
}
