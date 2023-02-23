NAME = cub3d

SRC		=	main.c parsing.c parsing_utils.c  parsing2.c init.c GNL_utils/get_next_line.c GNL_utils/get_next_line_utils.c \
			libft_utils/ft_strdup.c \
			libft_utils/ft_isdigit.c libft_utils/ft_split.c libft_utils/ft_strjoin.c libft_utils/ft_tolower.c libft_utils/ft_substr.c

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