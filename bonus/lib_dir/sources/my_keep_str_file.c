/*
** EPITECH PROJECT, 2020
** BTTF_BSQ
** File description:
** my_st_size.c
*/

#include "../includes/my.h"

char *my_keep_str_file(char *filepath)
{
    struct stat st;
    char *buf;
    int fd;

    stat(filepath, &st);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    buf = malloc(sizeof(char) * st.st_size);
    if (st.st_size != read(fd, buf, st.st_size))
        return NULL;
    return buf;
}