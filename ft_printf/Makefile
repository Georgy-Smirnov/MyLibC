# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjaco <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:27:17 by kjaco             #+#    #+#              #
#    Updated: 2021/04/03 14:43:51 by kjaco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## START_MAKEFILE ##

#==================================>COLORS<====================================#

_RED		=	\e[31m
_YELLOW		=	\e[33m
_GREEN		=	\e[32m
_END		=	\e[0m

#==================================>FILES<=====================================#

SRC			=	ft_print_int.c \
				ft_printf.c \
				ft_print_percent.c \
				ft_print_bighex.c \
				ft_print_pointer.c \
				ft_second_part.c \
				ft_print_char.c \
				ft_print_string.c \
				ft_print_hex.c \
				ft_print_unint.c


SRCS		=	$(SRC)

#===============================>COMPILATIONS<=================================#

GCC			=	gcc

AR			=	ar rc

CFLAGS		=	-Wall -Werror -Wextra

#===================================>DELETE<===================================#

RM			=	rm -rf

#=================================>DIRECTORIES<================================#

DIR_HEAD	=	./

DIR_SRCS	=	./

DIR_OBJS	=	./object_files/

#===============================>COMPILED_SOURCES<=============================#

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

NAME		=	Libprintf.a

LIBFT	=	./Libft.a

#================================>COMPILED_RULES<==============================#

all:			${NAME}

${NAME}:		${OBJS}
				@cp ${LIBFT} ${NAME}
				@${AR} ${NAME} ${OBJS}
				@ranlib ${NAME}
				@printf "\033[2K\r${_GREEN} Library create: '${NAME}'. ${_END}✅\n"


#===========================>COMPILED_SOURCES_RULES<===========================#

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				@$(GCC) $(CFLAGS) -I $(DIR_HEAD) -c $< -o $@
				@printf "\033[2K\r$(_YELLOW) Compiling $< $(_END)⌛"

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)

#==========================>MINI_TEST_RULES<===========================#

test:			${NAME}
				@${GCC} test.c ${NAME} && ./a.out	

#==========================>CLEAN_RULES<==========================#

clean:
				@${RM} ${DIR_OBJS}
				@${RM} ./a.out
				@printf "\033[2K\r${_RED} '".o"' has been deleted. ${_END}🗑️\n"

fclean:			clean	
				@${RM} ${NAME}
				@printf "\033[2K\r${_RED} '"${NAME}"' has been deleted. ${_END}🗑️\n"

re:				fclean all

.PHONY: all clean fclean test re
