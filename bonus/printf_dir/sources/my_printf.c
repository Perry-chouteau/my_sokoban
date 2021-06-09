/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf
*/

#include "../includes/my_printf.h"
#include <stdarg.h>

int my_printf(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i += 1) {
        if (s[i] == '%') {
            cond_lowslowcid(list, s, i);
            cond_lowxob(list, s, i);
            cond_m(list, s, i);
            i = cond_more_less(list, s, i);
            i = cond_diez(list, s, i);
            i += 1;
        }
        else
            putchar_printf(s[i]);
    }
    va_end(list);
    return 0;
}
