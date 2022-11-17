# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2022/11/14 15:04:00 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= extension.c get_next_line.c ft_strcmp.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c ft_putchar.c \
	ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
	ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c \
	ft_substr.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c \
	ft_strlen.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_sort_int_tab.c ft_whitespace.c
 
BSRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

BOBJS		= ${BSRCS:.c=.o}

NAME		= libft.a

CC			= gcc -g

CFLAGS		= -Wall -Wextra -Werror

all :        ${NAME}

.c.o :		${OBJS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS} printf.a
			ar rc ${NAME} ${OBJS} ft_printf/libftprintf.a

bonus :		${BOBJS} ${OBJS}
	ar rcs ${NAME} ${BOBJS} ${OBJS}

printf.a :
	make -C ft_printf

clean :
			rm -f ${OBJS} ${BOBJS}
			make -C ft_printf clean

fclean :	clean
			rm -f ${NAME} 
			make -C ft_printf fclean

re :        fclean all

.PHONY : all clean fclean re bonus
