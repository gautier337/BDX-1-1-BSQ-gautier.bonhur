/*
** EPITECH PROJECT, 2021
** bsq 
** File description:
** checkpath
*/

#include "../include/my.h"

int fs_open_file(char const *filepath)
{
    int to_return = open(filepath, O_RDONLY);
    struct stat stat_t;

    stat(filepath, &stat_t);
    if (stat_t.st_size < 4)
        to_return = -1;
    close(to_return);
    return to_return;
}
