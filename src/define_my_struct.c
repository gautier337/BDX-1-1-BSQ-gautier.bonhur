/*
** EPITECH PROJECT, 2021
** define struct
** File description:
** bsq
*/

#include "../include/my.h"

s defstr(int index_nbr_cols, int index_nbr_rows, int s_check)
{
    s my_struct;

    my_struct.index_nb_cols = index_nbr_cols;
    my_struct.index_nb_raws = index_nbr_rows;
    my_struct.size_to_check = s_check;

    return my_struct;
}