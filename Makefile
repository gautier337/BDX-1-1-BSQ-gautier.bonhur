##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile
##

SRC	=	src/my_getnbr.c \
		src/my_lenght_int.c \
		src/my_put_nbr.c \
		src/my_putchar.c \
		src/my_putstr.c \
		src/my_revstr.c \
		src/my_strcat.c \
		src/my_strlen.c \
		src/utility.c \
		src/define_my_struct.c \
		src/check_path_errors.c \
		algo1.c

SRC_TESTS =

NAME = bsq

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(OBJ)
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean all