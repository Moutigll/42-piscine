NAME = ft_display_file

SRC = main.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
