# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 18:19:48 by lprior            #+#    #+#              #
#    Updated: 2018/05/06 18:23:11 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_display.c ft_free.c ft_sort.c ft_tools.c ft_tools2.c ft_utilities.c \
       ft_utilities2.c main.c

FLAGS = -Wall -Wextra -Werror

NAME = ft_ls

LIBFT = libft

all: $(NAME)

$(NAME):
	@echo "\033[32mCompiling source files\033[0m"
	@make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

clean:
	@echo "\033[32mCleaning up\033[0m"
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "\033[32mFull clean\033[0m"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean all re