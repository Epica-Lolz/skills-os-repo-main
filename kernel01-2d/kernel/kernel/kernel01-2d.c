#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <kernel/tty.h>

void print_scroller(){
    int counter=0;//index variable to scroll through all characters of the array
    int nl_ctr=0;//index variable for number of newlines
    char point[] = "SkillsUSA 01-2d\nMeme\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n";//char array
    printf(point);//print(char-array)
    while(point[counter]!='\0'){//while the array is not empty
        counter++;//count all characters of the array
        if(point[counter]=='\n'){//if the character is a newline
            nl_ctr++;//increment number of newlines
            if(nl_ctr>=26){//if this number is larger than 26 (max number of columns for vga)
                term_scroll();//scroll the terminal
                nl_ctr-=1;//decrement the newline counter (because it only counts the number of on-screen newlines
            }
        }
    }
}

void kmain(void){
    term_init();//call term_init function defined in tty.c
    print_scroller();//call print_scroller
    for(;;){
        char ch=getchar();
        printf("%c", ch);
    }
}
