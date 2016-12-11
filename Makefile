# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 10:32:42 by hsabouri          #+#    #+#              #
#    Updated: 2016/11/27 17:24:21 by hsabouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBPATH = libft
LIBNAME = libft.a
LIB = $(LIBNAME:%=$(LIBPATH)/%)
CFLAGS = -Wall -Werror -Wextra -I$(LIBPATH)/includes
LDFLAGS = -L $(LIBPATH) -l$(LIBNAME:lib%.a=%)
CC = gcc
SRC	= ft_error.c main.c solve.c ft_filetomem.c verifications.c\
	  board.1.c board.2.c board.3.c
INC = fillit.h
OBJ	= $(SRC:%.c=%.o)

all: $(NAME) 

$(LIB):
	$(MAKE) -C $(LIBPATH)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(LDFLAGS) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBPATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBPATH)

re: fclean
	$(MAKE) all

norme:
	@norminette $(SRC) $(INC)
	@$(MAKE) norme -C $(LIBPATH)

.PHONY: all clean fclean re norme
