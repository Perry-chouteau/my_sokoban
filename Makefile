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

SRC_MAIN	=	sources/main.c

SRC_TEST	=	tests/test_error_handling.c

OBJ =	$(SRC_LIB:.c=.o)	\
		$(SRC_PRINTF:.c=.o)	\
		$(SRC:.c=.o)	\
		$(SRC_MAIN:.c=.o)

NAME = my_sokoban

NAME_TEST = unit_tests

CPPFLAGS	=	-I ./includes

CFLAGS	=	-W -Wall -Wextra

GCOVR	=	gcovr

TESTSFLAGS	=	--coverage -lcriterion

LDFLAGS	=	-lncurses

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

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

unit_tests:	fclean
	$(CC) -o $(NAME_TEST) $(SRC) $(SRC_LIB) $(SRC_PRINTF) $(SRC_TEST) $(TESTSFLAGS) $(LDFLAGS) $(CPPFLAGS)

tests_run: unit_tests
	./unit_tests
	#$(GCOVR) --exclude tests/
	#$(GCOVR) -b --exclude tests/
	rm -rf *.gcda && rm -rf *.gcno

.PHONY: all clean fclean re unit_tests tests_run