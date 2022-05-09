##
## EPITECH PROJECT, 2021
## B-CPE-100-TLS-1-1-cpoolday10-younes1.bahri
## File description:
## Makefile
##

SRC		=		math/my_compute_power_rec.c \
				math/my_compute_square_root.c \
				math/my_find_prime_sup.c \
				math/my_is_prime.c \
				math/my_isneg.c \
				converter/my_getnbr.c \
				converter/my_atof.c	\
				printer/printf_utilities/handler_convert.c \
				printer/printf_utilities/handler_put_nbr.c \
				printer/printf_utilities/handler_put_str_and_char.c \
				printer/my_put_nbr.c \
				printer/my_putchar.c \
				printer/my_putstr.c \
				printer/my_get_index.c \
				printer/my_convert_decimal_to_base.c \
				printer/my_printf.c \
				printer/my_showstr.c \
				string/my_revstr.c \
				array/my_sort_int_array.c \
				char/check_char_pos.c \
				char/check_isalpha.c \
				string/my_str_isalpha.c \
				string/my_str_islower.c \
				string/my_str_isnum.c \
				string/my_str_isprintable.c \
				string/my_str_isupper.c \
				string/my_strcapitalize.c \
				string/my_strcat.c \
				string/my_strcmp.c \
				string/my_strcpy.c \
				string/my_strlen.c \
				string/my_strlowcase.c \
				string/my_strncat.c \
				string/my_strncmp.c \
				string/my_strncpy.c \
				string/my_strstr.c \
				string/my_strupcase.c \
				string/my_strdup.c 	\
				string/replace_str.c \
				number/my_swap.c \
				number/get_length_long.c \
				number/get_valid_int.c

OBJ =			$(SRC:.c=.o)

NAME = 			libmy.a

CFLAGS	=	-I../../include

all:	$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm	-f ../$(NAME)

re: fclean all
