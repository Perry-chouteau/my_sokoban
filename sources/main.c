/*
** EPITECH PROJECT, 2020
** Psu3
** File description:
** main.c
*/

#include "../includes/include.h"

int print(s_t *s);

int sokoban(s_t *s);

int main(int ac, char **av)
{
    s_t *s;
    if (my_error(ac, av) == 1)
        return 0;
    if (my_error(ac, av) == 84)
        return 84;
    s = malloc(sizeof(s_t));
    if (init(s, av) == 84)
        return 84;
    return sokoban(s);
}