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

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRC:.c=.o)

all: libft $(NAME)

$(NAME):
	$(AR)

clean:

fclean:

re: fclean all
	