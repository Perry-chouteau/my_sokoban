/*
** EPITECH PROJECT, 2020
** Socoban preshot
** File description:
** game_status.c
*/

#include "../includes/include.h"

int lose(s_t *s)
{
    free_all(s);
    exit(1);
}

int win(s_t *s)
{
    free_all(s);
    exit(0);
}