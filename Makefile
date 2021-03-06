# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 15:46:40 by thgillai          #+#    #+#              #
#    Updated: 2021/09/17 09:32:40 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME		=	src/main.c			\
				src/open.c			\
				src/cmd.c			\
				src/path.c	

SRCS		= ${SRCNAME}

OBJS		= ${SRCS:.c=.o}

NAME		= pipex

CC			= gcc -g -fsanitize=address
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I -I./inc/libft

CGREEN		= \033[38;2;0;153;0m
CRED		= \033[0;31m
CYELLOW		= \033[0;33m
CGREY		= \033[38;2;128;128;128m
CEND		= \033[0m


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@echo
		@echo "$(CYELLOW)Compilation of Libft$(CEND)"
		@echo "$(CGREY)"
		make -C ./inc/libft
		@echo
		${CC} -o ${NAME} ${OBJS} -L./inc/libft -lft
		@echo "$(CEND)"
		@echo "$(CGREEN)Compilation done !$(CEND)"
		@echo

all:		${NAME}

clean:
		@echo
		@echo "$(CYELLOW)Deleting .o files$(CEND)"
		@echo "$(CGREY)"
		make -C ./inc/libft clean
		${RM} ${OBJS}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

fclean:		clean
		@echo "$(CYELLOW)Deleting .o files, libft.a and pipex$(CEND)"
		@echo "$(CGREY)"
		${RM} ${NAME} ./inc/libft/libft.a outfile.txt
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

re: 		fclean all

c: 			all clean

.PHONY: 	clean fclean all re