#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lusantor <lusantor@student.42.rio>         +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2022/09/19 17:30:39 by lusantor          #+#    #+#             *#
#*   Updated: 2022/09/19 00:39:51 by lusantor         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libftprintf.a
CFLAGS	=	-Wall -Wextra -Werror -c

SRC = ft_printf.c ft_puts.c minilibft.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ft_printf.h $(OBJ)
	$(AR) -rcs $(NAME) $(OBJ)

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	$(CC) test.c libftprintf.a
	./a.out
	$(RM) a.out
