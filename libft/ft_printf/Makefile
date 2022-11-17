# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2022/10/07 11:43:20 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_iterative_power.c ft_printf.c ft_putchar.c ft_putnbr_unsign.c \
			  ft_putnbr_base.c ft_putnbr_base_ptr.c ft_putstr.c ft_strchr.c \
			  ft_strlen.c ft_putnbr.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all :        ${NAME}

.c.o :		${OBJS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean :
			rm -f ${OBJS}
			
fclean :	clean
			rm -f ${NAME} 

re :        fclean all

.PHONY : all clean fclean re bonus
