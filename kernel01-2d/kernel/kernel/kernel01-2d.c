#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <kernel/tty.h>

void print_scroller(){
    int counter=0;
    int nl_ctr=0;
    char point[] = "SkillsUSA 01-2d\nMeme\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23";
    printf(point);
    while(point[counter]!='\0'){
        counter++;
        if(point[counter]=='\n'){
            nl_ctr++;
            if(nl_ctr>=26){
                term_scroll();
                nl_ctr-=1;
            }
        }
    }
}

void kmain(void){
    term_init();//call term_init function defined in tty.c
    print_scroller();
}
