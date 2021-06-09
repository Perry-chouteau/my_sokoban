/*
** EPITECH PROJECT, 2020
** Psu3
** File description:
** test_error_handling.c
*/

#include "include.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_all_std(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

//.init = redirect_all_std

Test(Err, Bad_arg)
{
    int ac = 1;
    char **av;

    cr_assert_eq(my_error(ac, av), 84);
}

Test(Err, Help, .init = redirect_all_std)
{
    int ac = 2;
    char *av[2] = {"ex", "-h"};

    cr_assert_eq(my_error(ac, av), 1);
    cr_assert_stdout_eq_str("USAGE\n"
                            "\t./sokoban file\n"
                            "\n"
                            "DESCRIPTION\n"
                            "\tYou need to push all the box 'X' in the 'O'"
                            "with the player 'P' to win\n"
                            "\n"
                            "KEYBOARD\n"
                            "\tSpace: restart\n"
                            "\tArrow: move P\n");
}

//Test(Err, All_is_fine, .init = redirect_all_std)
//{
//    int ac = 2;
//    char **av = 2;
//    s_t *s = {0};
//    cr_assert_eq(init(s,ac, av), 0);
//}
