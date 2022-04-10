##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Solver
##

SRC =	src/main.c \
		src/error/verif_map.c	\
		src/error/error_handling.c \
		src/file/open_file.c \
		src/init_struct.c \
		src/backtracking/backtracking.c	\

OBJ = $(SRC:.c=.o)

NAME = solver

CFLAGS += -W -Wall -Wextra -I include

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: fclean $(NAME)

.PHONY: all clean fclean re debug
