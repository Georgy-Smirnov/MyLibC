# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjaco <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 20:20:47 by kjaco             #+#    #+#              #
#    Updated: 2021/04/03 14:02:17 by kjaco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## START_MAKEFILE ##

#===============================>COLORS<===============================#

_RED		=	\e[31m
_YELLOW		=	\e[33m
_GREEN		=	\e[32m
_END		=	\e[0m

# ===================================================================== #

#===============================>FILES<===============================#

SRCS		= ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strnstr.c \
			  ft_strncmp.c \
			  ft_atoi.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_delbeforechar.c \
			  ft_strjoin_with_frees1.c \
			  ft_get_next_line.c \
			  ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

# ===================================================================== #

#============================>COMPILATIONS<============================#

GCC			=	gcc

AR			=	ar rc

CFLAGS		=	-Wall -Werror -Wextra

#===============================>DELETE<===============================#

RM			=	rm -f

#============================>HEADER_FILE<============================#

DIR_HEAD	=	./libft.h

#==========================>COMPILING_RULES<==========================#

OBJS		=	${SRCS:%.c=%.o}

NAME		=	Libft.a

all:			${NAME}

${NAME}:		${OBJS}
				@${AR} ${NAME} ${OBJS}
				@ranlib ${NAME}
				@printf "\033[2K\r${_GREEN} Library create: '${NAME}'. ${_END}✅\n"

%.o:			%.c
				@printf "\033[2K\r${_YELLOW} ⌛ Compilling $< ${_END}\n"
				@${GCC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

#==========================>NORM_RULES<===========================#

norm:
				@norminette *.c
				@norminette *.h				

#==========================>CLEAN_RULES<==========================#

clean:
				@${RM} ${OBJS}
				@printf "\033[2K\r${_RED} '".o"' has been deleted. ${_END}🗑️\n"

fclean:			clean	
				@${RM} ${NAME}
				@printf "\033[2K\r${_RED} '"${NAME}"' has been deleted. ${_END}🗑️\n"

re:				fclean all

.PHONY: all clean fclean norm re
