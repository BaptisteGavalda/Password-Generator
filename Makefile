SRC	= passgen.c \
	  functions.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -std=c99

LDFLAGS	+= -W -Wextra -Wall -Werror

BINDIR	= /usr/bin/

NAME	= passgen

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: install
install:
	install -m 557 $(NAME) $(BINDIR)

.PHONY: uninstall
uninstall:
	rm -f $(BINDIR)$(NAME)
