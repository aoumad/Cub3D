# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 07:22:21 by aelabid           #+#    #+#              #
#    Updated: 2023/03/04 12:11:04 by aoumad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = execution/check_wall.c execution/color_background.c execution/cub3d.c\
		execution/dda.c execution/get_texture_image.c execution/handle_key.c\
		execution/init_player.c execution/init.c execution/my_mlx_put.c\
		execution/open_windows.c execution/rays.c execution/render_image.c\
		execution/render_recs.c execution/sizes.c execution/rays_util.c \
		execution/rays_util2.c \
		pars/parsing_utils_2.c pars/parsing_additional_2.c pars/parsing_additional_3.c pars/parsing4.c\
		pars/parsing_additional.c pars/parsing.c pars/parsing_utils.c  pars/parsing2.c pars/init.c pars/GNL_utils/get_next_line.c pars/GNL_utils/get_next_line_utils.c \
		pars/libft_utils.c pars/mouse.c pars/parsing3.c pars/ft_split.c\

OBJ = $(SRC:.c=.o)

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror
CC = gcc

# LIBFT = pars/libft/libft.a

all : $(LIBFT) $(NAME)


%.o: %.c pars/parsing.h pars/libft_utils/libft.h pars/libft_utils/get_next_line.h includes/cub3d.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C pars/libft

clean :
	rm -f $(OBJ) 

fclean : clean
	rm -f $(NAME) 

re : fclean all