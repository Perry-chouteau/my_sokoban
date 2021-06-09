/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** definition de fonction
*/

#ifndef MATH_H
#define MATH_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "../../lib_dir/includes/my.h"

#define PI acos(-1.0)

typedef struct
{
    int x;
    int y;
}vec2i_t;

typedef struct
{
    int x;
    int y;
    int z;
}vec3i_t;

typedef struct
{
    double x;
    double y;
}vec2f_t;

typedef struct
{
    double x;
    double y;
    double z;
}vec3f_t;

#endif
