# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 19:37:18 by jvaquer           #+#    #+#              #
#    Updated: 2020/01/23 23:56:14 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT

DIR_SRCS =		./src/

SRC = 		image/ft_image.c image/ft_save_bmp.c \
			image/ft_print_error.c image/miniRT_close_win.c \
			\
			vector/ft_math_aux.c vector/ft_vector.c \
			vector/ft_vector2.c vector/ft_vector3.c \
			\
			objs/ft_cylinder.c objs/ft_for_each_obj.c objs/ft_plane.c \
			objs/ft_sphere.c objs/ft_square.c objs/ft_triangle.c \
			\
			parse/ft_ambiance_res.c parse/ft_camera_light.c \
			parse/ft_check_file.c parse/ft_parse_cy.c \
			parse/ft_parse_obj.c parse/ft_parse_pl.c \
			parse/ft_parse_sp.c parse/ft_parse_sq.c \
			parse/ft_parse_tr.c parse/ft_parse_utils.c parse/ft_set_ori.c \
			\
			raytrace/ft_draw.c raytrace/ft_color.c raytrace/ft_effects.c \
			raytrace/ft_color_utils.c \
			\
			utils/miniRT_utils.c utils/ft_reset_lst.c \
			utils/ft_atod.c utils/ft_atoi.c utils/ft_isdigit.c \
			utils/ft_strlen_nb.c utils/ft_strcmp.c utils/ft_strlen.c \
			utils/ft_strncmp.c \ 
			\
			miniRT.c

OBJS =	$(SRCS:.c=.o)

SRCS =	$(addprefix $(DIR_SRCS), $(SRC))

CC =	gcc

FRAME = 	-framework OpenGL -framework AppKit

LMINX =		-I /usr/local/include -L /usr/local/lib -lmlx

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	gcc $(FRAME) $(CFLAGS) $(LMINX) -o $(NAME) $(OBJS)

clean:
	rm -f srcs/*.o srcs/*/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all