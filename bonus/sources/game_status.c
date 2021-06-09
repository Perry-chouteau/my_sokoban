/*
** EPITECH PROJECT, 2020
** Socoban preshot
** File description:
** game_status.c
*/

#include "../includes/include.h"

int restart(s_t *s)
{
    s->move = 0;
    clear();
    for (int i = 0, k = 0, j; s->buf[k] != '\0'; i += 1, k += 1)
        for (j = 0; s->buf[k] != '\n' && s->buf[k]; j += 1, k += 1)
            s->tab[i][j] = s->buf[k];
    s->p_pos.x = -1;
    s->p_pos.y = -1;
    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j] != '\0'; j += 1)
            if (s->tab[i][j] == 'P') {
                s->p_pos.y = i;
                s->p_pos.x = j;
            }
}

int lose(s_t *s)
{
    s->ch = '\0';
    for (clear(); 1; s->ch = getch()) {
        mvprintw(1, 4, "Y   Y OOOOO U   U   L     OOOOO SSSSS EEEEE");
        mvprintw(2, 4, " Y Y  O   O U   U   L     O   O S     E    ");
        mvprintw(3, 4, "  Y   O   O U   U   L     O   O SSSSS EEEE ");
        mvprintw(4, 4, "  Y   O   O U   U   L     O   O     S E    ");
        mvprintw(5, 4, "  Y   OOOOO UUUUU   LLLLL OOOOO SSSSS EEEEE");
        mvprintw(9, 1, "Press 'SPACE' to restart or 'Q' key to leave");
        refresh();
        if (s->ch == ' ') {
            restart(s);
            return 0;
        } else if (s->ch == 'q') {
            free_all(s);
            exit(1);
        }
    }
}

int win(s_t *s)
{
    s->ch = '\0';
    for (clear(); 1; s->ch = getch()) {
        mvprintw(1, 4, "Y   Y OOOOO U   U   W   W OOOOO N   N");
        mvprintw(2, 4, " Y Y  O   O U   U   W   W O   O NNN N");
        mvprintw(3, 4, "  Y   O   O U   U   W W W O   O N NNN");
        mvprintw(4, 4, "  Y   O   O U   U   WWWWW O   O N  NN");
        mvprintw(5, 4, "  Y   OOOOO UUUUU   WW WW OOOOO N   N");
        mvprintw(7, 16, "in %i Moves", s->move);
        mvprintw(9, 1, "Press 'SPACE' to restart or 'Q' key to leave");
        refresh();
        if (s->ch == ' ') {
            restart(s);
            return 0;
        } else if (s->ch == 'q') {
            free_all(s);
            exit(2);
        }
    }
}

int check2_x(s_t *s, int i, int j)
{
    if ((( s->tab[i + 1][j] == 'X' ||  s->tab[i + 1][j] == '#') &&
    (s->tab[i][j + 1] == 'X' ||  s->tab[i][j + 1] == '#') &&
    ( s->tab[i + 1][j + 1] == 'X' ||  s->tab[i + 1][j + 1] == '#')) ||
    (( s->tab[i + 1][j] == 'X' ||  s->tab[i + 1][j] == '#') &&
    (s->tab[i][j - 1] == 'X' ||  s->tab[i][j - 1] == '#') &&
    ( s->tab[i + 1][j - 1] == 'X' ||  s->tab[i + 1][j - 1] == '#')) ||
    (( s->tab[i - 1][j] == 'X' ||  s->tab[i - 1][j] == '#') &&
    (s->tab[i][j + 1] == 'X' ||  s->tab[i][j + 1] == '#') &&
    ( s->tab[i - 1][j + 1] == 'X' ||  s->tab[i - 1][j + 1] == '#')) ||
    (( s->tab[i - 1][j] == 'X' ||  s->tab[i - 1][j] == '#') &&
    (s->tab[i][j - 1] == 'X' ||  s->tab[i][j - 1] == '#') &&
    ( s->tab[i - 1][j - 1] == 'X' ||  s->tab[i - 1][j - 1] == '#')))
        return Lose;
    return Continue;
}