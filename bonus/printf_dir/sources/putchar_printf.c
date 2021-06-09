/*
** EPITECH PROJECT, 2020
** putchar_printf
** File description:
** putchar_printf.c
*/
#include "../includes/my_printf.h"
#include <unistd.h>

void putchar_printf(char c)
{
    write(1, &c, 1);
}
