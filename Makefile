# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebhakaz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 17:02:06 by ebhakaz           #+#    #+#              #
#    Updated: 2021/05/13 18:28:06 by ebhakaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= ./libft

LIBFT		= libft.a

NAME		= libftprintf.a

SRC			= ft_printf.c ft_isflag_istype.c ft_parse_flag.c ft_parse_param.c ft_parse_char_and_str.c ft_parse_pointer.c ft_parse_int.c ft_parse_uint.c ft_parse_hex.c ft_parse_per.c

OBJ			= $(SRC:.c=.o)

FLAGS		= -Wall -Wextra -Werror

RM			= rm -f

%.o:		%.c ft_printf.h
			gcc $(FLAGS) -c $< -o $(<:.c=.o) -I.

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) bonus -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
			ar rcs $(NAME) $(OBJ)

clean:
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

test:		re
			gcc $(FLAGS) -g -I ft_printf.h -o test main.c $(NAME)

.PHONY:		all clean fclean re
