/*
** EPITECH PROJECT, 2020
** Socoban preshot
** File description:
** free_all.c
*/

#include "../includes/include.h"

void free_all(s_t *s)
{
    endwin();
    for (int i = 0; s->tab[i] != NULL; i += 1)
        free(s->tab[i]);
    free(s->tab);
    free(s->x_pos);
    free(s->buf);
    free(s);
}