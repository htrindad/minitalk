NAME = server

SERVER_NAME = server
CLIENT_NAME = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = ./ft_printf/libftprintf.a

PSLIB_DIR = ./pslib
PSLIB = ./pslib/pslib.a

FC_LIB = make fclean -C
COMP_LIB = make -s -C

all: $(NAME)

$(NAME): $(OBJ_SERVER) $(OBJ_CLIENT) $(FT_PRINTF) $(PSLIB)
	cc $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) -o $(SERVER_NAME)
	cc $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) $(PSLIB) -o $(CLIENT_NAME)

$(FT_PRINTF):
	$(COMP_LIB) $(FT_PRINTF_DIR)

$(PSLIB):
	$(COMP_LIB) $(PSLIB_DIR)

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)

fclean: clean
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)
	$(FC_LIB) $(FT_PRINTF_DIR)
	$(FC_LIB) $(PSLIB_DIR)

re: fclean all
