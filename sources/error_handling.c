/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** init.c
*/

#include "../includes/include.h"

void describe(void)
{
    my_printf("USAGE\n");
    my_printf("\t./sokoban file\n");
    my_printf("\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tYou need to push all the box 'X' in the 'O'\
with the player 'P' to win\n");
    my_printf("\n");
    my_printf("KEYBOARD\n");
    my_printf("\tSpace: restart\n");
    my_printf("\tArrow: move P\n");
}

int my_error(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        describe();
        return 1;
    }
    if (ac != 2)
        return 84;
    return 0;
}