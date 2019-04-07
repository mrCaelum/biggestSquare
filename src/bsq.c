/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** bsq
*/

#include "bsq.h"

int get_y(int file, int *result)
{
    unsigned char rcv_char = 0;
    int size_rcv = 0;
    int size = 0;

    while (rcv_char != '\n') {
        size_rcv = read(file, &rcv_char, 1);
        if (rcv_char < '0' || rcv_char > '9' || !size_rcv)
            return (size);
        *result = *result * 10 + rcv_char - 48;
        size++;
    }
    return (size);
}

unsigned char **fill_buffer(int file, int width, int height)
{
    unsigned char **buffer;
    int size_rcv;
    char tmp;

    buffer = malloc(sizeof(char *) * height);
    for (int line = 0; line < height; line++) {
        buffer[line] = malloc(sizeof(char) * width);
        size_rcv = read(file, buffer[line], width);
        read(file, &tmp, 1);
        if (tmp != '\n' || !size_rcv)
            exit(84);
    }
    for (int i = 0; i < width; i++)
        buffer[0][i] = buffer[0][i] == 'o' ? 0 : 1;
    for (int i = 1; i < height; i++)
        buffer[i][0] = buffer[i][0] == 'o' ? 0 : 1;
    for (int y = 1; y < height; y++)
        for (int x = 1; x < width; x++)
            buffer[y][x] = buffer[y][x] == 'o' ? 0 : square_size(buffer, x, y);
    return (buffer);
}

unsigned char **find_square(unsigned char **tab, int width, int height)
{
    square_t greater;

    greater.size = 0;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            greater.x = tab[y][x] > greater.size ? x : greater.x;
            greater.y = tab[y][x] > greater.size ? y : greater.y;
            greater.size = tab[y][x] > greater.size ? tab[y][x] : greater.size;
        }
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            tab[y][x] = tab[y][x] == 0 ? 'o' : (x > greater.x - greater.size &&
            x <= greater.x && y > greater.y - greater.size && y <= greater.y) ?
            'x' : '.';
        }
    return (tab);
}

void print_tab(unsigned char **tab, int width, int height)
{
    for (int y = 0; y < height; y++) {
        write(1, tab[y], width);
        write(1, "\n", 1);
    }
}

void free_tab(unsigned char **tab, int height)
{
    for (int i = 0; i < height; i++)
        free(tab[i]);
    free(tab);
}
