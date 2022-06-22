# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 01:36:36 by jusato            #+#    #+#              #
#    Updated: 2022/06/20 17:22:27 by jusato           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf.c ft_printf_utils.c
OBJS =		$(SRCS:.c=.o)
INCLUDES =	.
LIB =		libft/libft.a

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
AR =		ar -rcs
RM =		rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(LIB)
	$(CC) $(CFLAGS) -c $(SRCS) -I.

$(LIB):
	make -C ./libft
	cp $(LIB) $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
