# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 01:36:36 by jusato            #+#    #+#              #
#    Updated: 2022/07/06 21:36:20 by jusato           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf.c ft_printf_formats.c ft_printf_utils_1.c\
			ft_printf_utils_2.c
OBJS =		$(SRCS:.c=.o)
LIB =		libft/libft.a

# COMPILE
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
AR =		ar -rcs
RM =		rm -f

# TARGETS
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

bonus: all

.PHONY: all clean fclean re
