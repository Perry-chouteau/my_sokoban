/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** say character of a string, one by one
*/

#include "../includes/my_printf.h"
#include <unistd.h>

void putstr_printf(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i += 1);
    write(1, str, i);
    return ;
}

