##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compile our projects
##

NAME = unit

UT_SRC = test.c

SRC =	../src/utils.c			\
		../src/check_error.c	\
		../src/player.c

CFLAGS = -W -Wall -Wextra -I ../include

OBJ = $(SRC:%.c=%.o) $(UT_SRC:%.c=%.o)

LIB = -L ../../Criterion/build/ -lcriterion -L ../lib/my -lmy

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
