# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 12:17:51 by jfinet            #+#    #+#              #
#    Updated: 2018/09/06 17:50:24 by jfinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi_up.c ft_bzero.c ft_itoa.c ft_itoa_base.c ft_printf.c ft_strlen.c ft_strnew.c handle_data.c handle_precision.c sign_handler.c ft_putstr_count.c ft_putchar_count.c handle_octa.c handle_hexa.c handle_deci.c handle_str.c handle_c.c unicode.c handle_zero_d.c handle_zero_x.c handle_zero_o.c ft_strjoin_free.c ft_strcat.c check_flags.c

BIN = ft_atoi_up.o ft_bzero.o ft_itoa.o ft_itoa_base.o ft_printf.o ft_strlen.o ft_strnew.o handle_data.o handle_precision.o sign_handler.o ft_putstr_count.o ft_putchar_count.o handle_octa.o handle_hexa.o handle_deci.o handle_str.o handle_c.o unicode.o handle_zero_d.o handle_zero_x.o handle_zero_o.o ft_strjoin_free.o ft_strcat.o check_flags.o

all : $(NAME)

$(NAME) :
	gcc -I. -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
