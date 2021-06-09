/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** definition de fonction
*/

#ifndef MY_H
#define MY_H

//lib - lib_c
#include <stdlib.h>
#include <string.h>

//write
#include <unistd.h>
#include <stdio.h>

//signal
#include <signal.h>
#include <stddef.h>

// sys & bits
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

//criterion
#include <criterion/criterion.h>

//color
#define RESET_ALL "\x1b[0m"
#define PC_BOLD "\x1b[1m"
#define PC_ITALIC "\x1b[3m"
#define UNDER_LINE "\x1b[4m"
#define UNDER_LINE_   "\x1b[21m"
#define FT_GREY "\x1b[2m"
#define FT_BLACK   "\x1b[30m"
#define FT_RED  "\x1b[31m"
#define FT_GREEN   "\x1b[32m"
#define FT_YELLOW  "\x1b[33m"
#define FT_BLUE "\x1b[34m"
#define FT_MAGENTA "\x1b[35m"
#define FT_CYAN "\x1b[36m"
#define BG_BLACK   "\x1b[40m"
#define BG_RED  "\x1b[41m"
#define BG_GREEN   "\x1b[42m"
#define BG_YELLOW  "\x1b[43m"
#define BG_BLUE "\x1b[44m"
#define BG_MAGENTA "\x1b[45m"
#define BG_CYAN "\x1b[46m"

//████████████████████████████████████████████████//

//linklist
typedef struct cell_s
{
    int data;
    struct cell_s *next;
}cell_t;

//double_linklist

//████████████████████████████████████████████████//

//math
void my_sort_int_array(int *tab, int size);

int my_str_isnum(char const *str);
int my_isneg(int nb);
int my_getnbr(char const *str);

int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);

double my_atof(char *str);
double my_sqrt(int nb);

//write
void my_putchar(char c);

int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_showstr(char const *str);

void my_swap(int *a, int *b);

//string > string
int my_strlen(char const *str);
int my_str_isalpha(char const *str);
int my_str_isprintable(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_showmem(char const *str, int size);

//string > string
char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char *src, int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strdup(char const *src);

//linklist
cell_t *empty_list(void);
int len_list(cell_t **);
void add_at(cell_t **, int, int);
int get_at(cell_t **, int);
void set_at(cell_t **, int, int);
void free_at(cell_t **, int);
void free_list(cell_t **);
void print_list(cell_t **);

#endif
