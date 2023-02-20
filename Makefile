NAME = cub3d

SRC		=	main.c parsing.c parsing_utils.c  parsing2.c init.c GNL/get_next_line.c GNL/get_next_line_utils.c \
			libft/ft_strdup.c \
			libft/ft_isdigit.c libft/ft_split.c libft/ft_strjoin.c libft/ft_tolower.c libft/ft_substr.c

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror -Ofast -g -fsanitize=address

# MLXFLAGS = -framework OpenGL -framework Appkit

# MLX = minilibx/libmlx.a

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS)

%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(NAME) $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re