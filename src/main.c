/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Main function for bsq
*/

#include "bsq.h"

static int bsq(int file, int x)
{
    unsigned char **tab;
    square_t greater;
    int y = 0;

    x = (x - get_y(file, &y) - 1) / y - 1;
    if (x < 1 || y < 1)
        return (84);
    tab = fill_buffer(file, x, y);
    if (!tab)
        return (84);
    tab = find_square(tab, x, y);
    if (!tab)
        return (84);
    print_tab(tab, x, y);
    free_tab(tab, y);
    close(file);
    return (0);
}

int main(int argc, char const *argv[])
{
    struct stat stat_size;
    int file;

    if (argc == 2 && argv[1][0] == '-' && ((argv[1][1] == 'h' && !argv[1][2])
    || (argv[1][1] == '-' && argv[1][2] == 'h' && argv[1][3] == 'e' &&
    argv[1][4] == 'l' && argv[1][5] == 'p' && !argv[1][6]))) {
        write(1, PRINT_HELP, HELP_SIZE);
        return (0);
    }
    stat(argv[1], &stat_size);
    if (stat_size.st_size < 1)
        return (84);
    file = open(argv[1], O_RDONLY);
    if (file == -1)
        return (84);
    return (bsq(file, stat_size.st_size));
}
