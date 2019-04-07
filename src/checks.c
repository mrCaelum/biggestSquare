/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** Check functions
*/

#include "bsq.h"

unsigned char square_size(unsigned char **tab, int x, int y)
{
    unsigned char tmp = tab[y - 1][x - 1];

    if (tab[y - 1][x] < tmp)
        tmp = tab[y - 1][x];
    if (tab[y][x - 1] < tmp)
        tmp = tab[y][x - 1];
    tmp++;
    return (tmp);
}
