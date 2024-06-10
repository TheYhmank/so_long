CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I/home/ayermeko/final_project/extra_libs/MLX42
LDFLAGS = -L/home/ayermeko/final_project/extra_libs/MLX42/build -lmlx42 -lglfw -lm -ldl -lpthread

SRCS = src/so_long.c
OBJS = $(SRCS:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
