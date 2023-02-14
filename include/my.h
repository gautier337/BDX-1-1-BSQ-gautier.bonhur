/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** my_strcapitalize
*/

#ifndef MY_H
    #define MY_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

typedef struct struct_pos {
    int index_nb_raws;
    int index_nb_cols;
    int size_to_check;
    int tmp;
} s;
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int fs_open_file(char const *filepath);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *my_strcat(char *dest, char const *src);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
int fs_get_number_from_first_line(char const *filepath);
s defstr(int index_nbr_cols, int index_nbr_rows, int s_check);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_col);
int lenght_int(int nbr);
char *my_revstr(char *str);
int issize(char **map, int row, int col, int square_size);
int fs_get_nbr_of_cols(char const *filepath);
#endif