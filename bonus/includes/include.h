/*
** EPITECH PROJECT, 2020
** Psu2
** File description:
** navy.h
*/

#ifndef ITSC_H
#define ITSC_H

//lib - lib_c
#include "../lib_dir/includes/my.h"
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

//write
#include "../printf_dir/includes/my_printf.h"
#include <unistd.h>
#include <stdio.h>

//math
#include "../math_dir/includes/math.h"
#include <math.h>

//signal
#include <signal.h>
#include <stddef.h>

// sys & bits
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//criterion
#include <criterion/criterion.h>

// enum
typedef enum
{
    Continue, Win, Lose, Pause, Restart, Quit, Null
}status_t;

// struct

typedef struct
{
    char *buf;

    int ch;
    char **tab;
    vec2i_t p_pos;

    int nb_place;
    vec2i_t *x_pos;

    int move;

    status_t game_status;
}s_t;

//file to buf
char *my_keep_str_file(char *filepath);

// error / -h
void describe(void);
int my_error(int ac, char **av);

//init
int init(s_t *s, int ac, char **av);

//key
int key_movement(s_t *s);
int changes(s_t *s);
int win(s_t *s);
int lose(s_t *s);
int check2_x(s_t *s, int i, int j);
int restart(s_t *s);

//free
void free_all(s_t *s);

#endif