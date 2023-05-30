# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 23:35:39 by ohamadou          #+#    #+#              #
#    Updated: 2023/05/30 13:01:10 by ohamadou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printchar.c \
		ft_printnbr.c \
		ft_printpercent.c \
		ft_printptr.c \
		ft_printstr.c \
		ft_printunsigned.c \
		ft_printf.c \
		ft_printf_utils.c \
		ft_printhex.c 
		
# LIBFTFILES = ft_itoa.c ft_atoi.c ft_itoa.c \
# 		ft_putchar_fd.c ft_strlen.c \
		
# LIBFTSRCS = $(addprefix libft/,$(LIBFTFILES))

OBJ = $(SRCS:.c=.o)
# LIBFTOBJS = $(LIBFTSRCS:.c=.o)


CFLAGS = -Wall -Werror -Wextra

CC = cc

all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h
		ar -rc $(NAME) $(OBJ)

# %.o : %.c ftprintf.h
# 	${cc} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all fclean re