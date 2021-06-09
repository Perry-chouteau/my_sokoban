/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** my_printf.h
*/

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

int my_printf(char *s, ...);
void putchar_printf(char c);
void putstr_printf(char *str);
void putnbr_printf(int nb);
char *revstr_printf(char *str);
void putnbr_convertlow_printf(unsigned int num, int base);
void putnbr_convertup_printf(unsigned int num, int base);
void cond_lowslowcid(va_list list, char *s, int i);
int cond_more_less(va_list list, char *s, int i);
void cond_lowxob(va_list list, char *s, int i);
int cond_diez(va_list list, char *s, int i);
int cond_mod(va_list list, char *s, int i);
void cond_m(va_list list, char *s, int i);

#endif