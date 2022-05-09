##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/fill_default_map.c	\
		src/generate_rooms.c	\
		src/generate_corridors.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include -Wall -Wextra -pedantic -g3

LFLAGS = -L./lib/ -ljson_parser -llist -lmy

NAME	=	generator

#------------------------------

all:	$(NAME)

$(NAME): build

build: $(OBJ)
	$(MAKE) -C ./lib/my
	$(MAKE) -C ./lib/linked_list
	$(MAKE) -C ./lib/json_parser
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LFLAGS)

clean:
	$(MAKE) -C ./lib/my clean
	$(MAKE) -C ./lib/linked_list clean
	$(MAKE) -C ./lib/json_parser clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./lib/my fclean
	$(MAKE) -C ./lib/linked_list fclean
	$(MAKE) -C ./lib/json_parser clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean build all
