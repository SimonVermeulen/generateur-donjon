##
## EPITECH PROJECT, 2021
## BistroMatic
## File description:
## Makefile
##

SRC	=	parsing/json_parser.c						\
		parsing/get_buffer.c						\
		parsing/stringify.c							\
		parsing/get_data.c							\
		parsing/get_key.c							\
		parsing/type_checkers/check_type.c			\
		parsing/type_checkers/check_array.c			\
		parsing/type_checkers/check_object.c		\
		parsing/type_checkers/check_double.c		\
		parsing/type_checkers/check_int.c			\
		parsing/type_checkers/check_string.c		\
		parsing/value_getters/get_value.c			\
		parsing/value_getters/get_array.c			\
		parsing/value_getters/get_object.c			\
		parsing/value_getters/get_double.c			\
		parsing/value_getters/get_int.c				\
		parsing/value_getters/get_string.c			\
		utils/free_json.c							\
		utils/copy/copy_double.c					\
		utils/copy/copy_int.c						\
		utils/copy/copy_json.c						\
		utils/copy/copy_string.c					\
		utils/copy/copy_value.c						\
		writing/launch_writing.c					\
		writing/loop.c								\
		writing/writers/double_writer.c				\
		writing/writers/int_writer.c				\
		writing/writers/object_writer.c				\
		writing/writers/string_writer.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I../../include -Wall -Wextra -pedantic -g3

LFLAGS =	-L./lib -llist

NAME	=	libjson_parser.a

#------------------------------

all:	$(NAME)

$(NAME): $(OBJ)
	ar -ro $(NAME) $(OBJ)
	cp $(NAME) ./../

clean:
	rm	-f $(OBJ)

fclean: clean
	rm	-f $(NAME)
	rm	-f ../$(NAME)

re: fclean all

.PHONY: re fclean clean build all
