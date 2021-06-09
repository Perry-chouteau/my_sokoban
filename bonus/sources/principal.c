/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/include.h"

int print(s_t *s)
{
        mvprintw(0, 0, "__________________________________________");
        mvprintw(1, 0, "| MOVE: arrows ( )| RESTART:'_'| EXIT:'Q'|");
        mvprintw(2, 0, "|_________________|____________|_________|");
        mvprintw(3, 0, "| NB OF MOVES:         | NB OF BOX:      |");
        mvprintw(4, 0, "|______________________|_________________|");
        for (int y = 0; s->tab[y] != NULL; y += 1)
            mvprintw(y + 6, 15, "%s", s->tab[y]);
        mvprintw(3, 37, "%i", s->nb_place);
        mvprintw(3, 17, "%i", s->move);
}

int sokoban(s_t *s)
{
    s->move = 0;
    clear();
    for (s->ch = 'a'; 1 && s->ch != 'q'; s->ch = getch()) {
        changes(s);
        print(s);
        refresh();
    }
    free_all(s);
    return 0;
}

int main(int ac, char **av)
{
    s_t *s;
    int ret;
    if (my_error(ac, av) == 1)
        return 0;
    if (my_error(ac, av) == 84)
        return 84;
    s = malloc(sizeof(s_t));
    if (init(s, ac, av) == 84)
        return 84;
    return sokoban(s);
}