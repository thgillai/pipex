# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 13:17:14 by thgillai          #+#    #+#              #
#    Updated: 2021/08/05 15:50:43 by thgillai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		atoi.c strlen.c isalpha.c isdigit.c strchr.c putstr_fd.c \
			isalnum.c isascii.c isprint.c toupper.c tolower.c putnbr_fd.c \
			strncmp.c strlcpy.c strlcat.c strnstr.c strdup.c putendl_fd.c \
			strrchr.c memset.c bzero.c memcpy.c memccpy.c putchar_fd.c \
			memchr.c memcmp.c memmove.c calloc.c substr.c strjoin.c \
			lstnew.c lstadd_front.c lstsize.c lstlast.c listadd_back.c \
			lstdelone.c lstclear.c lstiter.c lstmap.c strtrim.c itoa.c \
			strmapi.c split.c ispace.c strcpy.c exit_error.c strcmp.c \
			../get_next_line/get_next_line.c \
			../get_next_line/get_next_line_utils.c \
			../get_next_line/norme_file.c \


OBJS =		${addprefix ${SRCDIR}, ${SRCS:.c=.o}}

NAME =		libft.a

CC = 		gcc -Wall -Wextra -Werror
RM = 		rm -f

CFLAGS =	-Wall -Wextra -Werror

SRCDIR = ./src/
HEADDIR = ./inc/

.c.o:
			${CC} ${CFLAGS} -I${HEADDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			@echo "${OUT_PREFIX}\033[38;5;46mLibrary compiled\033[0m"

all:		${NAME}

clean:
			${RM} ${OBJS}
			@echo "${OUT_PREFIX}\033[38;5;46mObjects cleaned\033[0m"

fclean:		clean
			${RM} ${NAME}
			@echo "${OUT_PREFIX}\033[38;5;46mLibrary cleaned\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
