# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 15:31:38 by ele-lean          #+#    #+#              #
#    Updated: 2024/08/26 15:48:10 by ele-lean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

HEADERS = $(INCDIR)/ft.h

all: $(NAME)

$(NAME): $(OBJ)
	@echo "ar rcs $(NAME) $(OBJ)"
	ar rcs $(NAME) $(OBJ)

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@echo "$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@"
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@echo "rm -f $(OBJ)"
	rm -f $(OBJ)

fclean: clean
	@echo "rm -f $(NAME)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
