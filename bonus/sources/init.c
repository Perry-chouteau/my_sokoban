/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** init.c
*/

#include "../includes/include.h"

void init_window(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
}

int str_to_tab(s_t *s, char *buf)
{
    int y = 1;
    if (buf == NULL)
        return 84;
    for (int i = 0; buf[i] != '\0'; i += 1)
        y += (buf[i] == '\n')? 1: 0;
    s->tab = malloc(sizeof(char *) * (y + 1));
    s->tab[y] = NULL;
    for (int i = 0, k = 0, j; buf[k] != '\0'; i += 1, k += 1) {
        for (j = 0; buf[k + j] != '\n' && buf[k + j]; j += 1);
        s->tab[i] = malloc(sizeof(char) * (j + 1));
        s->tab[i][j] = '\0';
        for (j = 0; buf[k] != '\n' && buf[k]; j += 1, k += 1)
            s->tab[i][j] = buf[k];
    }
    s->buf = buf;
    return 0;
}

int init_place(s_t *s)
{
    int nb_box = 0;
    int tmp = 0;

    s->nb_place = 0;
    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j] != '\0'; j += 1)
            s->nb_place += (s->tab[i][j] == 'O')? 1 : 0;
    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j] != '\0'; j += 1)
            nb_box += (s->tab[i][j] == 'X')? 1: 0;
    if (s->nb_place == 0 || s->nb_place != nb_box)
        return 84;
    s->x_pos = malloc(sizeof(vec2i_t) * (s->nb_place));
    for (int i = 0; s->tab[i] != NULL && tmp < s->nb_place; i += 1)
        for (int j = 0; s->tab[i][j] != '\0'; j += 1)
            if (s->tab[i][j] == 'O') {
                s->x_pos[tmp].y = i;
                s->x_pos[tmp].x = j;
                tmp += 1;
            }
}

int init_player(s_t *s)
{
    s->p_pos.x = -1;
    s->p_pos.y = -1;
    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j] != '\0'; j += 1)
            if (s->tab[i][j] == 'P') {
                s->p_pos.y = i;
                s->p_pos.x = j;
            }
    if (s->p_pos.x == -1 || s->p_pos.y == -1)
        return 84;
}

int init(s_t *s, int ac, char **av)
{
    char *buf = my_keep_str_file(av[1]);

    if (buf == NULL) {
        endwin();
        free(s);
        return 84;
    }
    str_to_tab(s, buf);
    init_window();
    if (init_player(s) == 84 || init_place(s) == 84) {
        free_all(s);
        endwin();
        return 84;
    }
    return 0;
}