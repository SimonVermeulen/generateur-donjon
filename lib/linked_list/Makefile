##
## EPITECH PROJECT, 2021
## linked list
## File description:
## makefile
##

SRC	=	add_delete_element.c	\
		create_empty_list.c		\
		add_delete_node.c		\
		search.c

OBJ	=	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -pedantic -I../../include -g3

NAME	=	liblist.a

#--------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ./../

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)
	rm	-f ../$(NAME)

re: fclean all

.PHONY: re fclean clean all
