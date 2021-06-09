/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Cette fonction permet de comparer deux chaînes de caractères
*/

#include "../includes/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (;(s1[i] == s2[i]) && s1[i] && s2[i]; i += 1);
    return (s1[i] - s2[i]);
}