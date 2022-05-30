# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 19:37:18 by jvaquer           #+#    #+#              #
#    Updated: 2020/02/08 11:10:08 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./inc/

DIR_SRCS =		./src/

DIR_OBJS =		./

FRAME =			-framework OpenGl -framework AppKit

LMINX = 	libmlx.a

SRC = 		image/ft_image.c image/ft_save_bmp.c \
			image/ft_print_error.c image/minirt_close_win.c \
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
			parse/ft_parse_utils2.c \
			\
			raytrace/ft_draw.c raytrace/ft_color.c raytrace/ft_effects.c \
			raytrace/ft_color_utils.c raytrace/ft_draw_utils.c \
			\
			utils/minirt_utils.c utils/ft_reset_lst.c \
			utils/ft_atod.c utils/ft_atoi.c utils/ft_isdigit.c \
			utils/ft_strlen_nb.c utils/ft_strcmp.c utils/ft_strlen.c \
			utils/ft_strncmp.c \
			\
			minirt.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(FLAGS) $(FRAME)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(OBJS) $(LMINX) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
