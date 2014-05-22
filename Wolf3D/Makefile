#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 17:59:00 by pkesslas          #+#    #+#              #
#    Updated: 2014/01/09 18:31:31 by pkesslas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC_C = main.c \
		ft_hook.c \
		ft_calc.c \
		ft_put_image.c \
		ft_dda.c \
		ft_init_map.c \
		ft_print_wall.c \

SRC_O = $(SRC_C:.c=.o)

SRC_H = wolf.h

SRC_A = libft/libft.a

FLAG = -Wall -Wextra -Werror

LIB = -L./libft -lft -L/usr/X11/lib -lXext -lX11 -lmlx

all		: $(NAME)

$(NAME)	: $(SRC_O)
		make -C libft/
		cc $(FLAG) -o $(NAME) $^ $(LIB)

%.o: %.c
		cc $(FLAG) -I libft/includes/ -c $<

clean	:
		make -C libft/ clean
		rm -f $(SRC_O)

fclean	: clean
		make -C libft/ fclean
		rm -f $(NAME)

re		: fclean all
