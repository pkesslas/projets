#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/26 12:58:05 by pkesslas          #+#    #+#              #
#    Updated: 2014/03/25 10:50:41 by pkesslas         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = cc

NAME = rt

SRC_C = main.c \
		ft_light.c \
		ft_perlin.c \
		ft_shadow.c \
		ft_misc.c \
		file_param.c \
		file_paramn.c \
		file_paramn2.c \
		file_paramn3.c \
		ft_apply_text.c \
		ft_antialiasing.c \
		ft_checkerboard.c \
		ft_env.c \
		ft_textur_sphr.c \
		ft_types.c \
		ft_types2.c \
		lib.c \
		lib2.c \
		math.c \
		rotate.c \
		con.c \
		ft_draw.c \
		ft_ini.c \
		math.c \
		pla.c \
		sph.c \
		cyl.c \
		cub.c \
		bmp.c \
		cub2.c \
		lpl.c \
		ft_reflect.c \
		ft_reflect2.c \
		file_paramn4.c

BMP = mirror.bmp rt.bmp

SRC_O = $(SRC_C:.c=.o)

SRC_H = rt.h

FLAG = -Wall -Wextra -Werror

LIB = -L/usr/X11/lib -lXext -lX11 -lmlx

all		: $(NAME)

$(NAME)	: $(SRC_O)
		$(CC) $(FLAG) -g -o $(NAME) $^ $(LIB)

%.o: %.c
		$(CC) $(FLAG) -c $<

clean	:
		rm -f $(SRC_O) $(BMP)

fclean	: clean
		rm -f $(NAME)

clang	: CC = cc
clang	: all

re		: fclean all

.PHONY	: all re clean fclean clang
