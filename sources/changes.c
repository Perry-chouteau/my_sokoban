/*
** EPITECH PROJECT, 2020
** Socoban preshot
** File description:
** changes.c
*/

#include "../includes/include.h"

int check_place(s_t *s)
{
    for (int n = 0; n < s->nb_place; n += 1)
        if (s->tab[s->x_pos[n].y][s->x_pos[n].x] == ' ')
            s->tab[s->x_pos[n].y][s->x_pos[n].x] = 'O';
    return 0;
}

int check_win(s_t *s)
{
    for (int n = 0; n < s->nb_place; n += 1)
        if (s->tab[s->x_pos[n].y][s->x_pos[n].x] != 'X')
            return Continue;
    return Win;
}

int check_x(s_t *s, int i, int j)
{
    if ((s->tab[i + 1][j] == '#' && s->tab[i][j + 1] == '#') ||
        (s->tab[i + 1][j] == '#' && s->tab[i][j - 1] == '#') ||
        (s->tab[i - 1][j] == '#' && s->tab[i][j + 1] == '#') ||
        (s->tab[i - 1][j] == '#' && s->tab[i][j - 1] == '#'))
            return -1;
    return Continue;
}

int check_lose(s_t *s)
{
    int n = 0;

    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j]; j += 1)
            if (s->tab[i][j] == 'X') {
                if (check_x(s, i, j) == -1)
                    n += 1;
                else
                    return Continue;
            }
    if (n == s->nb_place)
        return Lose;
    return 0;
}

int changes(s_t *s)
{
    key_movement(s);
    check_place(s);
    return 0;
}