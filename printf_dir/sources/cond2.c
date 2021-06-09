/*
** EPITECH PROJECT, 2020
** cond1
** File description:
** condition my_printf
*/

#include "../includes/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

void cond_m(va_list list, char *s, int i)
{
    if (s[i + 1] == 'm')
        putstr_printf("Success");
    if (s[i + 1] == '%')
        putchar_printf('%');
    if (s[i + 1] == 'b')
        putnbr_convertlow_printf(va_arg(list, int), 2);
}
