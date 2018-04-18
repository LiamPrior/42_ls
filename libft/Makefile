# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liamprior <liamprior@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/24 19:14:15 by lprior            #+#    #+#              #
#    Updated: 2018/03/11 20:51:42 by liamprior        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_isprint.c ft_memcpy.c ft_strcat.c ft_strlcat.c ft_strncpy.c \
ft_toupper.c ft_isalnum.c ft_memccpy.c ft_strchr.c ft_strlen.c ft_strnstr.c \
ft_isalpha.c ft_memmove.c ft_strcmp.c ft_strrchr.c ft_atoi.c ft_isascii.c \
ft_memchr.c ft_strcpy.c ft_strncat.c ft_strstr.c ft_bzero.c ft_isdigit.c \
ft_memcmp.c ft_memset.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_memalloc.c \
ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_wcount.c ft_swap.c ft_charcount.c ft_max.c ft_ishidden.c ft_strrev.c \
get_next_line.c

OBJECTS = ft_isprint.o ft_memcpy.o ft_strcat.o ft_strlcat.o ft_strncpy.o \
ft_toupper.o ft_isalnum.o ft_memccpy.o ft_strchr.o ft_strlen.o ft_strnstr.o \
ft_isalpha.o ft_memmove.o ft_strcmp.o ft_strrchr.o ft_atoi.o ft_isascii.o \
ft_memchr.o ft_strcpy.o ft_strncat.o ft_strstr.o ft_bzero.o ft_isdigit.o \
ft_memcmp.o ft_memset.o ft_strdup.o ft_strncmp.o ft_tolower.o ft_memalloc.o \
ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o \
ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o \
ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
ft_wcount.o ft_swap.o ft_charcount.o ft_max.o ft_ishidden.o ft_strrev.o \
ft_fwap.o ft_parsec.o ft_parsef.o ft_printf.o ft_basic_print.o ft_print_pup.o \
ft_wchar_bonus.o ft_parse_tools.o ft_check.o ft_prints.o ft_conversion_tools.o \
get_next_line.o

PRINTF = ./ft_printf/ft_fwap.c ./ft_printf/ft_parsec.c \
./ft_printf/ft_parsef.c ./ft_printf/ft_printf.c \
./ft_printf/ft_basic_print.c ./ft_printf/ft_print_pup.c \
./ft_printf/ft_wchar_bonus.c ./ft_printf/ft_parse_tools.c \
./ft_printf/ft_check.c ./ft_printf/ft_prints.c \
./ft_printf/ft_conversion_tools.c

$(NAME):
	gcc $(FLAGS) -c $(SRCS) $(PRINTF) -I $(NAME)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re