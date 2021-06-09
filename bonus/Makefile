##
## EPITECH PROJECT, 2020
## B-CPE-110-PAR-1-3-pushswap-perry.chouteau
## File description:
## Makefile
##

SRC_PRINTF =	printf_dir/sources/my_printf.c	\
				printf_dir/sources/cond1.c	\
				printf_dir/sources/cond2.c	\
\
				printf_dir/sources/convert_printf.c	\
				printf_dir/sources/putnbr_printf.c	\
				printf_dir/sources/putchar_printf.c	\
				printf_dir/sources/putstr_printf.c	\
				printf_dir/sources/revstr_printf.c

SRC_LIB =	lib_dir/sources/my_strcmp.c	\
\
			lib_dir/sources/my_keep_str_file.c

SRC =	sources/principal.c	\
		sources/init.c	\
		sources/error_handling.c	\
		sources/key_movement.c	\
		sources/free_all.c	\
		sources/changes.c	\
		sources/game_status.c

SRC_TEST = tests/*.c

OBJ =	$(SRC_LIB:.c=.o)	\
		$(SRC_PRINTF:.c=.o)	\
		$(SRC:.c=.o)

NAME = my_sokoban

NAME_TEST = unit_tests

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses -Wall -Wextra

clean:
	rm -rf *~
	cd sources/ && rm -rf *~
	cd printf_dir/sources/ && rm -rf *~
	cd lib_dir/sources/ && rm -rf *~
	rm -rf *.gcda && rm -rf *.gcno
	rm -rf $(NAME)
	rm -rf unit_tests

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(EXE)

re: fclean all