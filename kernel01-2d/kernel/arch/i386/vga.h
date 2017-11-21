#ifndef ARCH_I386_VGA_H
#define ARCH_I386_VGA_H

enum vga_color{
    c_black=0,
    c_blue=1,
    c_green=2,
    c_cyan=3,
    c_red=4,
    c_magenta=5,
    c_brown=6,
    c_light_grey=7,
    c_dark_grey=8,
    c_light_blue=9,
    c_light_green=10,
    c_light_cyan=11,
    c_light_red=12,
    c_light_magenta=13,
    c_light_brown=14,
    c_white=15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){ //vga entry color paramaters include a foreground and background. the foreground and background use all colors in the enumeration vga_color, and the colors are defined by later functions.
    return fg | bg << 4;//return foreground or background shifted left 4 bits.
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color){//'uc' is the characters of the string, and 'color' is the color used for the terminal text.
    return (uint16_t) uc | (uint16_t) color << 8;
}
#endif // ARCH_I386_VGA_H
