NAME = pslib.a

SRC = ps_strlen.c ps_atol.c ps_strdup.c ps_substr.c ps_split.c ps_stackcreate.c ps_strncmp.c ps_stackaddback.c \
      ps_stacklast.c ps_quiterror.c ps_freestack.c ps_freematrix.c ps_setindex.c ps_countnode.c ps_gethighest.c \
      ps_substr.c ps_strjoin.c ps_sorted.c ps_getlowest.c ps_highestval.c ps_stackaddfront.c \
      ps_getcheapest.c ps_duplicate.c ps_setprice.c ps_setcheapest.c ps_atoi.c ps_isdigit.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	ar -src $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
