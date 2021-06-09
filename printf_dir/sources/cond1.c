/*
** EPITECH PROJECT, 2020
** cond1
** File description:
** condition my_printf
*/


#include "../includes/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

void cond_lowslowcid(va_list list, char *s, int i)
{
    if (s[i + 1] == 's')
        putstr_printf(va_arg(list, char *));
    if (s[i + 1] == 'c')
        putchar_printf(va_arg(list, int));
    if (s[i + 1] == 'i' || s[i + 1] == 'd')
        putnbr_printf(va_arg(list, int));
    return ;
}

int cond_more_less(va_list list, char *s, int i)
{
    if (s[i + 1] == '+' && (s[i + 2] == 'i' || s[i + 2] == 'd')) {
        int s = va_arg(list, int);
        if (s >= 0)
            putchar_printf('+');
        putnbr_printf(s);
        i += 1;
    }

    if (s[i + 1] == ' ' && (s[i + 2] == 'i' || s[i + 2] == 'd')) {
        int s = va_arg(list, int);
        if (s >= 0)
            putchar_printf(' ');
        putnbr_printf(s);
        i += 1;
    }
    return i;
}

void cond_lowxob(va_list list, char *s, int i)
{
    if (s[i + 1] == 'x')
        putnbr_convertlow_printf(va_arg(list, unsigned int), 16);
    if (s[i + 1] == 'o')
        putnbr_convertlow_printf(va_arg(list, unsigned int), 8);
    if (s[i + 1] == 'X')
        putnbr_convertup_printf(va_arg(list, unsigned int), 16);
    return ;
}

int cond_diez(va_list list, char *s, int i)
{
    if (s[i + 1] == '#' && (s[i + 2] == 'x')) {
        putstr_printf("0x");
        putnbr_convertlow_printf(va_arg(list, unsigned int), 16);
        i += 1;
    }
    if (s[i + 1] == '#' && (s[i + 2] == 'X')) {
        putstr_printf("0X");
        putnbr_convertup_printf(va_arg(list, unsigned int), 16);
        i += 1;
    }
    return i;
}
