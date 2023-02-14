/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** write a function that copies a string into another
*/

int my_strlen(char const *str);

void my_swape(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int t;
    int lenght = my_strlen(str) -1;

    t = 0;
    while (lenght > t){
        my_swape(&str[lenght], &str[t]);
        lenght--;
        t++;
    }
    return str;
}
