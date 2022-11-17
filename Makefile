# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2022/11/17 18:02:22 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c check_files.c initialized.c free.c pars_arg.c exe_cmd.c
OBJS		= ${SRCS:.c=.o}
NAME		= pipex
CC			= clang -g -O0
CFLAGS		= -Wall -Wextra -Werror

all :        ${NAME}

.c.o :		${OBJS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS}
			make -C libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -Llibft -lft -Llibft/ft_printf -lftprintf

clean :
			rm -f ${OBJS} ${BOBJS}
			make -C libft clean

fclean :	clean
			rm -f ${NAME} 
			make -C libft fclean

re :
			make fclean
			make all

.PHONY : all clean fclean re bonus
