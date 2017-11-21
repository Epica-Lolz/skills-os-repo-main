#include <string.h>

void* memset(void* bufptr, int value, size_t size){//sets the first number of bytes (specified by 'size') of the block of memory 'bufptr' is pointing at to the value specified in value. (i.e. char meme[] = "extra meme"; memset(meme,'-',6); outputs "------extra meme".
	unsigned char* buf = (unsigned char*) bufptr;//unsigned char pointer array 'buf' is set to the value of 'bufptr' (set to the block of memory pointed to by 'bufptr') 
	for(size_t i=0;i<size;i++){//index is 0; index is less than the size of the 'value' being written to bufptr[]; index++
		buf[i] = (unsigned char) value;//value (casted as an unsigned char) is being written to the buffer (being written to the block of memory)
	}
	return bufptr;//return new value of block of memory
}
