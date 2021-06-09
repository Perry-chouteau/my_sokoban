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
}

int check_win(s_t *s)
{
    for (int n = 0; n < s->nb_place; n += 1)
        if (s->tab[s->x_pos[n].y][s->x_pos[n].x] != 'X')
            return 50;
    return Win;
}

int check_x(s_t *s, int i, int j)
{
    if (s->tab[i][j] == 'X') {
        for (int n = 0; n < s->nb_place; n += 1)
            if (s->x_pos[n].y == i && s->x_pos[n].x == j)
                return Continue;
        if ((s->tab[i + 1][j] == '#' && s->tab[i][j + 1] == '#') ||
        (s->tab[i + 1][j] == '#' && s->tab[i][j - 1] == '#') ||
        (s->tab[i - 1][j] == '#' && s->tab[i][j + 1] == '#') ||
        (s->tab[i - 1][j] == '#' && s->tab[i][j - 1] == '#'))
            return Lose;
    }
    return Continue;
}

int check_lose(s_t *s)
{
    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j]; j += 1) {
            if (check_x(s, i, j) == Continue)
                continue;
            else if (check2_x(s, i, j) == Lose)
                return Lose;
            else
                return Lose;
        }
}

int changes(s_t *s)
{
    key_movement(s);
    check_place(s);
    if (check_lose(s) == Lose)
        lose(s);
    if (check_win(s) == Win)
        win(s);
    if (s->ch == ' ')
        restart(s);
    return 0;
}