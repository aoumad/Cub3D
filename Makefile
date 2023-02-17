NAME = cub3d

SRC		=	main.c parsing.c parsing_utils.c  parsing2.c init.c GNL/get_next_line.c GNL/get_next_line_utils.c

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror -Ofast -g

MLXFLAGS = -framework OpenGL -framework Appkit

MLX = minilibx/libmlx.a

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) $(MLXFLAGS) $(MLX) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re