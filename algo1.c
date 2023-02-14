/*
** EPITECH PROJECT, 2021
** algo
** File description:
** 1
*/

#include "include/my.h"

s find_biggest_square(char **map, int nbr_cols, int nbr_rows, int s_check)
{
    int nbr_carac_int_map = nbr_cols * nbr_rows;
    int f = 0;
    int tmp = 0;
    int stop = 0;
    s my_struct;

    my_struct.tmp = 0;
    for (int i_rows = 0; i_rows < nbr_rows && stop == 0; i_rows++)
        for (int i_cols = 0; i_cols < nbr_cols && stop == 0; i_cols++) {
            f = issize(map, i_rows, i_cols, s_check);
            stop = (f == 1) ? 1 : 0;
            my_struct = (f == 1) ? defstr(i_cols, i_rows, s_check) : my_struct;
            my_struct.tmp = (f == 1) ? 1 : my_struct.tmp;
        }
    return my_struct;
}

s biggest_size(char **map, int nbr_cols, int nbr_raws)
{
    int max = 0;
    int i = 0;
    s my_struct;

    my_struct = find_biggest_square(map, nbr_cols, nbr_raws, i);
    for (; my_struct.tmp == 1; i++)
        my_struct = find_biggest_square(map, nbr_cols, nbr_raws, i);
    return my_struct;
}

void display(char **map, s my_struct, int nbr_rows, int nbr_cols)
{
    int size_to_edit = my_struct.size_to_check;

    for (int w = 0; w < size_to_edit; w++) {
        for (int z = 0; z < size_to_edit; z++)
            map[w + my_struct.index_nb_raws][z + my_struct.index_nb_cols] = 'x';
    }
    for (int x = 0; x <= nbr_rows; x++) {
        my_putstr(map[x]);
    }
}

int issize(char **map, int row, int col, int square_size)
{
    int row_index = row;
    int col_index = col;
    int to_return = 1;

    for (int i = 0; i < square_size && to_return != 0; i++) {
        col_index = col;
        for (; col_index < col + square_size && to_return != 0; col_index++) {
            to_return = (map[row_index][col_index] != '.') ? 0 : to_return;
        }
        row_index++;
    }
    return to_return;
}

int main(int argc, char **argv)
{
    if (argc != 2 || fs_open_file(argv[1]) == -1)
        return 84;

    char *path = argv[1];
    int nbr_raws = fs_get_number_from_first_line(path);
    int nbr_cols = fs_get_nbr_of_cols(path);

    char **map = load_2d_arr_from_file(path, nbr_raws, nbr_cols);
    display(map, biggest_size(map, nbr_cols, nbr_raws), nbr_raws, nbr_cols);
    return 0;
}