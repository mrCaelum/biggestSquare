/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Header file for bsq
*/

#ifndef BSQ_H_
    #define BSQ_H_
    
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #define PRINT_HELP USAGE DESC
    #define USAGE "USAGE\n\t./bsq [file]\n"
    #define DESC "DESCRIPTION\n\tfile: text file containing the map to solve\n"
    #define HELP_SIZE 77
    
    typedef struct square {
        int x;
        int y;
        int size;
    } square_t;
    
    int get_y(int file, int *result);
    unsigned char **fill_buffer(int file, int width, int height);
    unsigned char square_size(unsigned char **tab, int x, int y);
    unsigned char **find_square(unsigned char **tab, int width, int height);
    void free_tab(unsigned char **tab, int height);
    void print_tab(unsigned char **tab, int width, int height);
#endif
