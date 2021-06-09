/*
** EPITECH PROJECT, 2020
** Socoban preshot
** File description:
** key_movement.c
*/

#include "../includes/include.h"

int key_down(s_t *s)
{
    if (s->tab[s->p_pos.y + 1][s->p_pos.x] != '#') {
        if (s->tab[s->p_pos.y + 1][s->p_pos.x] == ' ' ||
        s->tab[s->p_pos.y + 1][s->p_pos.x] == 'O') {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y + 1][s->p_pos.x] = 'P';
            s->p_pos.y += 1;
            s->move += 1;
        } else if (s->tab[s->p_pos.y + 1][s->p_pos.x] == 'X' &&
        (s->tab[s->p_pos.y + 2][s->p_pos.x] == ' ' ||
        s->tab[s->p_pos.y + 2][s->p_pos.x] == 'O')) {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y + 1][s->p_pos.x] = 'P';
            s->tab[s->p_pos.y + 2][s->p_pos.x] = 'X';
            s->p_pos.y += 1;
            s->move += 1;
        }
    }
    return 0;
}

int key_up(s_t *s)
{
    if (s->tab[s->p_pos.y - 1][s->p_pos.x] != '#') {
        if (s->tab[s->p_pos.y - 1][s->p_pos.x] == ' ' ||
        s->tab[s->p_pos.y - 1][s->p_pos.x] == 'O') {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y - 1][s->p_pos.x] = 'P';
            s->p_pos.y -= 1;
            s->move += 1;
        } else if (s->tab[s->p_pos.y - 1][s->p_pos.x] == 'X' &&
        (s->tab[s->p_pos.y - 2][s->p_pos.x] == ' ' ||
        s->tab[s->p_pos.y - 2][s->p_pos.x] == 'O')) {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y - 1][s->p_pos.x] = 'P';
            s->tab[s->p_pos.y - 2][s->p_pos.x] = 'X';
            s->p_pos.y -= 1;
            s->move += 1;
        }
    }
    return 0;
}

int key_left(s_t *s)
{
    if (s->tab[s->p_pos.y][s->p_pos.x - 1] != '#') {
        if (s->tab[s->p_pos.y][s->p_pos.x - 1] == ' ' ||
        s->tab[s->p_pos.y][s->p_pos.x - 1] == 'O') {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y][s->p_pos.x - 1] = 'P';
            s->p_pos.x -= 1;
            s->move += 1;
        } else if (s->tab[s->p_pos.y][s->p_pos.x - 1] == 'X' &&
        (s->tab[s->p_pos.y][s->p_pos.x - 2] == ' ' ||
        s->tab[s->p_pos.y][s->p_pos.x - 2] == 'O')) {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y][s->p_pos.x - 1] = 'P';
            s->tab[s->p_pos.y][s->p_pos.x - 2] = 'X';
            s->p_pos.x -= 1;
            s->move += 1;
        return 0;
        }
    }
    return 0;
}

int key_right(s_t *s)
{
    if (s->tab[s->p_pos.y][s->p_pos.x + 1] != '#') {
        if (s->tab[s->p_pos.y][s->p_pos.x + 1] == ' ' ||
        s->tab[s->p_pos.y][s->p_pos.x + 1] == 'O') {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y][s->p_pos.x + 1] = 'P';
            s->p_pos.x += 1;
            s->move += 1;
        } else if (s->tab[s->p_pos.y][s->p_pos.x + 1] == 'X' &&
        (s->tab[s->p_pos.y][s->p_pos.x + 2] == ' ' ||
        s->tab[s->p_pos.y][s->p_pos.x + 2] == 'O')) {
            s->tab[s->p_pos.y][s->p_pos.x] = ' ';
            s->tab[s->p_pos.y][s->p_pos.x + 1] = 'P';
            s->tab[s->p_pos.y][s->p_pos.x + 2] = 'X';
            s->p_pos.x += 1;
            s->move += 1;
        }
    }
    return 0;
}

int key_movement(s_t *s)
{
    switch (s->ch) {
        case KEY_DOWN:
            key_down(s);
            break;
        case KEY_UP:
            key_up(s);
            break;
        case KEY_LEFT:
            key_left(s);
            break;
        case KEY_RIGHT:
            key_right(s);
            break;
    }
    return 0;
}