/*
** EPITECH PROJECT, 2020
** Convert
** File description:
** Convert dec base in other base
*/

#include "../includes/my_printf.h"
#include <stdlib.h>

void putnbr_convertlow_printf(unsigned int num, int base)
{
    static char *size_base = "0123456789abcdef";
    char *buffer = malloc(sizeof(char) * 4000);

    for (int i = 0; num > 0; i += 1) {
        int j = num % base;
        num = num / base;
        buffer[i] = size_base[j];
    }
    buffer = revstr_printf(buffer);
    putstr_printf(buffer);
    return ;
}

void putnbr_convertup_printf(unsigned int num, int base)
{
    static char *size_base = "0123456789ABCDEF";
    char *buffer = malloc(sizeof(char) * 4000);

    for (int i = 0; num > 0; i += 1) {
        int j = num % base;
        num = num / base;
        buffer[i] = size_base[j];
    }
    buffer = revstr_printf(buffer);
    putstr_printf(buffer);
    return ;
}

