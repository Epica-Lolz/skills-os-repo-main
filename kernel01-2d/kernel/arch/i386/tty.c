#include <stdbool.h> //c does not have booleans by default
#include <stddef.h>
#include <stdint.h>
#include <string.h> //implemented in a later addition to the libk library

#include <kernel/tty.h> //including the tty.h file i wrote in include/kernel

#include "vga.h" //calling the vga driver header file i wrote

static const size_t vga_w = 80;//defining vga terminal width
static const size_t vga_h = 25;//defining vga terminal height
static uint16_t* const vga_buffer = (uint16_t*) 0xB8000; //setting video stack as read-only pointer array and setting it to start at 0xB8000.

static size_t term_row;//variable for terminal row
static size_t term_column;//variable for terminal column
static uint8_t term_color;//variable for color of terminal
static uint16_t* term_buffer;//variable for terminal stack

void term_scroll();

uint16_t i = 0;

void term_init(void){
    term_row = 0;//setting terminal row to 0 for now
    term_column = 0;//setting terminal column to 0 for now
    term_color = vga_entry_color(c_green, c_black);//setting terminal color to vga_colors(green foreground, black background)
    term_buffer = vga_buffer;//setting terminal buffer to vga stack we declared.
    for(size_t y=0;y<vga_h;y++){//y is 0 and is less than the width of the terminal so we increment it.
        for(size_t x=0;x<vga_w;x++){//x is 0 and is less than the width of the terminal so we increment it.
            const size_t index = y*vga_w+x;//setting the index to be "y*vga_width+x"
            term_buffer[index]=vga_entry(' ',term_color);//if y and x are equal to 0 and are less than the terminal height and width and they are incremented to these values, fill the buffer with spaces and green text. (takes advantage of BIOS VGA driver.)
        }
    }
}

void term_setcolor(uint8_t color){
    term_color=color;//sets term_color to a color defined in this function
}

void term_putentryat(unsigned char c, uint8_t color, size_t x, size_t y){
    const size_t index = y*vga_w+x;//again we are declaring an index and setting it to "y*vga_width+x", only this time we are defining x and y in the function parameters
    term_buffer[index]=vga_entry(c, color);//char c is each character in the message, color is the color of the text. this snippet of code places the characters.
}

void term_putchar(char c){
    unsigned char uc = c;//defining an unsigned char for use in term_putentryat();
    term_putentryat(uc, term_color, term_column, term_row);//filling in the parameters for the input of characters. uc is the char array (the string), term_color is the color of the text used in the string, and term_row and term_column are used in place of the x and y variables used in the raw logic portion of this function (term_putentryat).
    if(++term_column==vga_w){//if term_column is equal to the width of the terminal, then reset term_column.
        term_column=0;//reset term_column;
        if(++term_row==vga_h){//if term_row is equal to the height of the terminal, then reset term_row.
            term_row=0;//reset term_row;
        }
    }
}

void term_newline(char n){
    term_putchar(n);
    if (n=='\n'){
        term_row++;
        term_column=0;
    }
}

void term_write(const char* data, size_t size){//defining a constant char pointer called data (for inputting the string), and a size_t variable named "size" (for finding the string length).
    for(size_t i=0;i<size;i++){//index = 0; index is less than the size; index += 1; basically goes through each individual character in the string.
        term_newline(data[i]);//data[i] is our string to be inputted later, this declaration is valid because pointers can serve as arrays.
    }
}

void term_writestring(const char* data){//const char* data is string.
    term_write(data, strlen(data));//data is entire string, and strlen(data) is each individual character of the string. strlen() is implemented in the strlen.c file.
}

void term_scroll()
{
    for(uint16_t y = 0; y < vga_h; y++){//setting y-coordinate initializer
        for(uint16_t x = 0; x < vga_w; x++){//setting x-coordinate initializer
            term_buffer[y*vga_w+x] = term_buffer[(y+1)*vga_w+x];//basically increments y by 1 and multiplies it by the vga_width + x
        }
    }
}

void term_scroll_check(){ //to check if number of newlines is greater than or equal to 26
    if(i>=26){//calling the exterior value i to fill in for term_row.
        while(i>=26){
            term_scroll();//calls term_scroll.
            i-=1;
        }
    }
}

