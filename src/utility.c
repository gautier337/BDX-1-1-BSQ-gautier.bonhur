/*
** EPITECH PROJECT, 2021
** bsq
** File description:
** needed information
*/

#include "../include/my.h"

char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_col)
{
    struct stat stat_t;
    stat(filepath, &stat_t);
    int size = stat_t.st_size;
    int fd = open(filepath, O_RDONLY);
    char **result = malloc(sizeof(char *) * nb_rows + 1);

    for (int i = 0; i <= nb_rows; i++) {
        if (i == 0) {
            result[0] = malloc(nb_col + lenght_int(nb_rows) + 2);
            read(fd, result[0], nb_col + lenght_int(nb_rows) + 2);
        } else {
            result[i] = malloc(nb_col + 1);
            read(fd, result[i], nb_col + 1);
        }
    }
    result[0] = my_revstr(result[0]);
    result[0][nb_col + 1] = '\0';
    result[0] = my_revstr(result[0]);
    close(fd);
    return result;
}

int fs_get_nbr_of_cols(char const *filepath)
{
    char *buff = malloc(sizeof(char) * 3146473648);
    int fd = open(filepath, O_RDONLY);
    int counter = 0;
    int i = 0;

    read(fd, buff, 3146473648);
    for (; buff[i] != '\n'; i++);
    i++;
    for (; buff[i] != '\n'; i++, counter++);
    close(fd);
    free(buff);

    return counter;
}

int fs_get_number_from_first_line(char const *filepath)
{
    int size = 16;
    char *buff = malloc(sizeof(char) * 16 + 1);
    char result[size];
    int fd = open(filepath, O_RDONLY);
    int found;

    if (fd == -1)
        return -1;
    buff[size] = '\0';
    read(fd, buff, size);
    for (int i = 0; buff[i] != '\n'; i++)
        result[i] = buff[i];
    found = my_getnbr(result);

    if (found <= 0)
        return - 1;
    close(fd);
    free(buff);
    return found;
}