##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_rpg
##

wc=$(foreach d,$(wildcard $1*),$(call wc,$d/,$2) $(filter $(subst *,%,$2),$d))

SRC_DIR = src/
SRC = $(call wc,$(SRC_DIR),*.c)
OBJ = $(SRC:.c=.o)
NAME = my_rpg
ARGS1 = -lcsfml-window -lcsfml-audio -lcsfml-system
ARGS2 = -lcsfml-window -lcsfml-graphics -lm

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(ARGS1) $(ARGS2)
	make clean

%.o: %.c
	gcc -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all run

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
