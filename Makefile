NAME_CLIENT = client
NAME_SERVER = server

CLIENT_SRCS = src/client.c
SERVER_SRCS = src/server.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = includes/

LIBFT = libft/libft.a
LIBFT_PATH = libft

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -I $(INCS) $(LIBFT) -o $(NAME_CLIENT) $(CLIENT_OBJS)
	ac rc $(NAME_CLIENT) $(CLIENT_OBJS)

$(NAME_SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -I $(INCS) $(LIBFT) -o $(NAME_SERVER) $(SERVER_OBJS)
	ac rc $(NAME_SERVER) $(SERVER_OBJS)

.c.o:
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(CLIENT_SRCS:.c=.o) $(SERVER_SRCS:.c=.o)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all bonus clean fclean re