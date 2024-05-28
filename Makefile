NAME	= minitalk

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

LIBFT = ./libft_full/libft.a
LIBFT_PATH = ./libft_full

SERVER_SRC		= server.c
CLIENT_SRC		= client.c

SERVER_O		= $(SERVER_SRC:.c=.o)
CLIENT_O		= $(CLIENT_SRC:.c=.o)

SERVER_NAME = server
CLIENT_NAME = client

all: libft $(SERVER) $(CLIENT)

libft:
	@$(MAKE) -C $(LIBFT_PATH)

$(SERVER_NAME): $(SERVER_O) $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER-NAME) $(SERVER_O) $(OBJS) $(LIBFT)

$(CLIENT_NAME): $(CLIENT_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_O) $(OBJS) $(LIBFT)

clean:
	$(RM) $(SERVER_O) $(CLIENT_O) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(SERVER_O) $(CLIENT_O)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

# .PHONY rule in order to avoid relinking
.PHONY: all clean fclean re libft
