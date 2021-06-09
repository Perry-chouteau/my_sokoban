/*
** EPITECH PROJECT, 2020
** revstr_printf.c
** File description:
** revstr_printf
*/

#include "../includes/my_printf.h"

char *revstr_printf(char *str)
{
    int i = 0;
    int n = 0;
    char b = 0;

    for (; str[i] != '\0'; i += 1);
    i -= 1;
    for ( n = 0; n < i ; n += 1, i -= 1) {
        b = str[i];
        str[i] = str[n];
        str[n] = b ;
    }
    return str;
}

