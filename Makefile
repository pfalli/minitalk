NAME	= minitalk

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

LIBFT = ./libft_full/libft.a
LIBFT_PATH = ./libft_full

SERVER_SRC		= server.c
CLIENT_SRC		= client.c

SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

SERVER = server
CLIENT = client

all: libft $(SERVER) $(CLIENT)

libft:
	@$(MAKE) -C $(LIBFT_PATH)

$(SERVER): $(SERVER_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(OBJS) $(LIBFT)

$(CLIENT): $(CLIENT_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(OBJS) $(LIBFT)

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
		$(RM) $(SERVER) $(CLIENT)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

# .PHONY rule in order to avoid relinking
.PHONY: all clean fclean re libft
